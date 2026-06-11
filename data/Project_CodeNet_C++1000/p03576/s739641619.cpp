#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 62;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N,K;
    cin >>N>>K;
    vector<ll>X(N);
    vector<ll>Y(N);
    rep(i,N){
        cin>>X[i]>>Y[i];
    }
    ll ans=INF;
    if(K==2){
        rep(i,N){
            rep3(j,i+1,N){
                ll X1=min({X[i],X[j]});
                ll X2=max({X[i],X[j]});
                ll Y1=min({Y[i],Y[j]});
                ll Y2=max({Y[i],Y[j]});
                chmin(ans,(X2-X1)*(Y2-Y1));
                        
            }
        }
    }else if(K==3){
        rep(i,N){
            rep3(j,i+1,N){
                rep3(k,j+1,N){

                    ll X1=min({X[i],X[j],X[k]});
                    ll X2=max({X[i],X[j],X[k]});
                    ll Y1=min({Y[i],Y[j],Y[k]});
                    ll Y2=max({Y[i],Y[j],Y[k]});

                    chmin(ans,(X2-X1)*(Y2-Y1));
                        
                    
                }
            }
        }
    }else{
        rep(i,N){
            rep3(j,i+1,N){
                rep3(k,j+1,N){
                    rep3(m,k+1,N){
                        ll X1=min({X[i],X[j],X[k],X[m]});
                        ll X2=max({X[i],X[j],X[k],X[m]});
                        ll Y1=min({Y[i],Y[j],Y[k],Y[m]});
                        ll Y2=max({Y[i],Y[j],Y[k],Y[m]});
                        ll cnt=0;
                        rep(n,N){
                            if(X[n]>=X1&&X[n]<=X2){
                                if(Y[n]>=Y1&&Y[n]<=Y2){
                                    cnt++;
                                }
                            }
                        }
                        //cout<<cnt<<endl;
                        if(cnt>=K){
                            chmin(ans,(X2-X1)*(Y2-Y1));
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;


    return 0;
    

}