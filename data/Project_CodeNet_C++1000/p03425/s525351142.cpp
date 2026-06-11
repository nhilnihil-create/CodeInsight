#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()

const vector<char> inp={'M','A','R','C','H'};



int main(){
    int n; cin>>n;
    vector<ll> p(5,0);
    rep(i,n){
        string a; cin>>a;
        rep(j,5){
            if(a[0]==inp[j]){
                p[j]++;
            }
        }
    }
    ll ans=0;
    rep(i,3){
        for(int j=i+1; j<=3; ++j){
            for(int k=j+1; k<=4; ++k){
                ans+=p[i]*p[j]*p[k];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}