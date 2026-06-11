#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<vector<int> > edges;
int main(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    edges.resize(4*n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        for(int q = 0; q < 2; q++){
            int num = 0;
            if(s[a] == 'A' && s[b] == 'A') num = 0;
            if(s[a] == 'A' && s[b] == 'B') num = 1;
            if(s[a] == 'B' && s[b] == 'B') num = 2;
            if(s[a] == 'B' && s[b] == 'A') num = 3;
            edges[4*a + num].push_back(4*b + (num+1) % 4);
            swap(a, b);
        }
    }
    vector<int> deg(4*n, 0);
    for(int a = 0; a < 4*n; a++){
        for(int b : edges[a]){
            deg[b]++;
        }
    }
    vector<int> bfs;
    int st = 0;
    for(int a = 0; a < 4*n; a++){
        if(deg[a] == 0) bfs.push_back(a);
    }
    while(st < bfs.size()){
        int a = bfs[st];
        st++;
        for(int b : edges[a]){
            deg[b]--;
            if(deg[b] == 0) bfs.push_back(b);
        }
    }
    
    if(bfs.size() < 4*n){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}