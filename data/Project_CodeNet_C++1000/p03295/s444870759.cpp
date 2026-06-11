#include<bits//stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int, int>> c;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        if(a > b){
            c.push_back(make_pair(a, b));
        }
        else{
            c.push_back(make_pair(b, a));
        }
    }
    sort(c.begin(),c.end());
    int now = 0;
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(now <= c[i].second){
            now = c[i].first;
            ans++;
        }
    }
    cout << ans << endl;
}
