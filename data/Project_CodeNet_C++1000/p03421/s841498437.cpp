#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N,A,B;
    cin>>N>>A>>B;
    if(N>A*B||N<A+B-1) cout <<-1<<"\n";
    else{
        if(B==1){
            rep(i,1,N+1){
                if(i==N) cout <<i<<"\n";
                else cout <<i<<" ";
            }
        }
        else{
            ll s=(N-A)/(B-1);
            ll u=(N-A)%(B-1)+1;
            ll t=N-B*s-u;
            rep(i,0,s){
                rep(j,0,B){
                    if(i==s-1&&j==B-1&&t<0) cout <<B*i+B-j<<"\n";
                    else cout <<B*i+B-j<<" ";
                }
            }
            if(t>0){
                rep(i,0,u){
                    cout <<B*s+u-i<<" ";
                }
                rep(i,0,t){
                    if(i<t-1) cout <<B*s+u+1+i<<" ";
                    else cout <<B*s+u+1+i<<"\n";
                }
            }
            if(t==0){
                rep(i,0,u){
                    if(i<u-1) cout <<B*s+u-i<<" ";
                    else cout <<B*s+u-i<<"\n";
                }
            }
        }
    }
}