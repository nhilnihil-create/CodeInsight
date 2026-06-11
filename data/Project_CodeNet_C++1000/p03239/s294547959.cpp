#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;
int main(){
    int n,t;
    cin >> n >> t;
    vector<pair<int,int>> vp(n);
    rep(i,n){
        cin >> vp.at(i).first >> vp.at(i).second;
    }
    
    int mnt = INF;
    for(auto p:vp){
        if(p.second <= t){
            mnt = min(mnt,p.first);
        }
    }
    if(mnt < INF) cout << mnt << endl;
    else cout << "TLE" << endl;

    return 0;
}