#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define rep(i,n) for(int64_t i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr int64_t INF=(1ll<<60);
constexpr int64_t mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> sum1,sum2;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(ll i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}
ll query(ll i,ll j,vector<ll> &s){//区間[i,j]の和
    return (s[j]-s[i]);
}

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];

    pre_process(v,sum1);
    reverse(v.begin(),v.end());
    pre_process(v,sum2);
    reverse(v.begin(),v.end());


    ll ans=0,sum=0;

    /*rep(i,sum1.size()) cout<<sum1[i]<<" ";
    cout<<endl;
    rep(i,sum2.size()) cout<<sum2[i]<<" ";
    cout<<endl;*/
    

    rep(left,min(n,k)+1){
        rep(right,min(n,k)+1-left){
            priority_queue<ll> que;

            sum=(sum1[left]+sum2[right]);
            rep(i,left+1){
                if(i==0) continue;
                que.push(-1*v[i-1]);
            }
            reverse(v.begin(),v.end());
            rep(i,right+1){
                if(i==0) continue;
                que.push(-1*v[i-1]);
            }
            reverse(v.begin(),v.end());

            rep(i,k-left-right){
                if(que.size()==0) continue;
                ll now=que.top();
                que.pop();
                if(now>0){
                    sum+=now;
                }else{
                    break;
                }
            }

            chmax(ans,sum);
        }
    }

    cout<<ans<<endl;
    return 0;
}