#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    
    vector<pair<int,int>> hasi;
    rep(i,M){
        int x,y; cin >> x >> y;
        hasi.push_back(pair(y,x));
    }
    
    sort(hasi.begin(),hasi.end());
    
    int now = hasi[0].first;
    int ans = 1;
    for(int i=1; i<M; i++){
        int a,b;
        a = hasi[i].first;
        b = hasi[i].second;
        if(b>=now){
            now = a;
            ans ++;
        }
    }
    cout << ans << endl;
}
