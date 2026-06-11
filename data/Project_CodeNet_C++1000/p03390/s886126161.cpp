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
    int Q;
    cin>>Q;
    rep(x,0,Q){
        ll A,B;
        cin>>A>>B;
        if(A==B) cout <<A+B-2<<"\n";
        else{
            if(A>B) swap(A,B);
            if(B==A+1){
                cout <<2*A-2<<"\n";
                continue;
            }
            ll t=ll(sqrt(A*B));
            if(A*B==t*t) t--;
            if(t*(t+1)<A*B){
                if(t==A) cout <<A-1+t<<"\n";
                else cout <<A-1+t+1+t-A-1<<"\n";
            }
            else{
                if(t==A)  cout <<A-1+t-1<<"\n";
                else cout <<A-1+t+t-A-1<<"\n";
            }
        }
    }
}