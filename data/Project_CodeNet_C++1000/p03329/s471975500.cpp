#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()


const vector<int> che={6,9};

int main(){
    int n; cin>>n;
    int ans=0;
    vector<int> p(n+5,-1);
    p[0]=0;
    rep(i,n){
        vector<int> cnt;
        rep(j,2){
            int a=che[j];
            rep(k,8){
                if((i+1)<pow(a,(k+1))) break;
                if(p[i+1-pow(a,k+1)]!=-1) cnt.push_back(p[i+1-pow(a,k+1)]+1);
            }
        }
        if(p[i]!=-1) cnt.push_back(p[i]+1);
        if(!cnt.empty()){
          sort(btoe(cnt));
          p[i+1]=cnt[0];
        }
    }
    cout<<p[n]<<endl;
}