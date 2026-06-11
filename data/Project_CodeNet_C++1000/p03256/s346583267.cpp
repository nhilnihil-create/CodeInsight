#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 200001;

int n, m;
string s;
vector <int> v[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    vector <int> a(n), b(n);
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(s[y] == 'A') a[x]++;
        else b[x]++;
        if(s[x] == 'A') a[y]++;
        else b[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    deque <int> ready;
    vector <int> vis(n);
    for(int i = 0 ; i < n ; i++){
        if(a[i] == 0 || b[i] == 0){
            ready.push_back(i);
            vis[i] = 1;
        }
    }
    while(ready.size()){
        int node = ready.front();
        ready.pop_front();
        for(auto &i : v[node]){
            if(vis[i]) continue;
            if(s[node] == 'A') a[i]--;
            else b[i]--;
            if(a[i] == 0 || b[i] == 0){
                ready.push_back(i);
                vis[i] = 1;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] > 0 && b[i] > 0) finish("Yes");
    }
    cout << "No" << endl;
}
