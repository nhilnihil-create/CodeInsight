#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io

    int n, m;
    map<int, int> mpd, mpt;
    cin>>n;
    vector<int> d(n);
    rep(i,n) {
        cin>>d[i];
        mpd[d[i]]++;
    }
    cin>>m;
    vector<int> t(m);
    rep(i,m) {
        cin>>t[i];
        mpt[t[i]]++;
    }

    for(int i=0;i<m;i++){
        int x=t[i];
        if(mpd[x]<mpt[x]){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    

    return 0;

}
