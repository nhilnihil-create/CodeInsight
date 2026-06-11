#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(long long i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll INF=(1ll<<60);
constexpr ll mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> sum;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(ll i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}

int main(){
    string s;cin>>s;
    ll n=s.size();
    vector<ll> num(n+1);
    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    bool prev=false;
    rep(i,n-1){
        if(s[i]==s[i+1]){
            if(prev==true){
                num[i]=-1;
                prev=false;
            }else{
                num[i]=1;
                prev=true;
            }
        }
    }

    pre_process(num,sum);

    ll one=0,zero=0;
    rep(i,n){
        if(sum[i]==0){
            zero++;
        }else{
            one++;
        }
    }

    cout<<min(one,zero)<<endl;


    return 0;
}