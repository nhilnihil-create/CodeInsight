#include <bits/stdc++.h>
using namespace std;typedef long long ll;typedef vector<ll> vl;typedef vector<vl> vvl;typedef pair<ll,ll> pl;typedef vector<pl> vp;const ll INF=1001001001;const ll LINF=1001001001001001001;const ll D4[]={0,1,0,-1,0};const ll D8[]={0,1,1,0,-1,-1,1,-1,0};template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()

void solve(long long N, std::vector<long long> A){
    ll ok=N,ng=0;
    while(ok-ng>1){
        ll m=(ok+ng)/2;

        ll len=0;
        vp x;
        rep(i,N){
            if(len<A[i]){
                x.emplace_back(0,A[i]-len);
                len=A[i];
            }else{
                pl p;
                while(len>=A[i]){
                    p=x.back();
                    x.pop_back();
                    len-=p.second;
                }
                if(p.first==m-1){
                    while(len>0&&p.first==m-1){
                        p=x.back();
                        x.pop_back();
                        len-=p.second;
                    }
                    if(p.first==m-1)break;
                    if(p.second>1){
                        x.emplace_back(p.first,p.second-1);
                    }
                    x.emplace_back(p.first+1,1);
                    len+=p.second;
                    if(len<A[i]){
                        x.emplace_back(0,A[i]-len);
                        len=A[i];
                    }
                }else{
                    if(A[i]-len>1){
                        x.emplace_back(p.first,A[i]-len-1);
                    }
                    x.emplace_back(p.first+1,1);
                    len=A[i];
                }
            }
        }
        if(len>0)ok=m;
        else ng=m;
    }
    cout<<ok<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
}
