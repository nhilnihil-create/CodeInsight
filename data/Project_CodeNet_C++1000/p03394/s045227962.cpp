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
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    if(N==3){
        cout <<2<<" "<<5<<" "<<63<<"\n";
        return 0;
    }
    else{
        if(N%2==0){
            vector<int> v;
            v.pb(3);
            v.pb(9);
            v.pb(2);
            v.pb(4);
            rep(i,0,min((N-4)/2,4999)){
                v.pb(6*(i+1)+2);
                v.pb(6*(i+1)+4);
            }
            rep(i,0,max(0,min((N-4)/2-4999,2499))){
                v.pb(12*(i+1)+3);
                v.pb(12*(i+1)+9);
            }
            rep(i,0,max(0,(N-4)-14996)){
                v.pb(6*(i+1));
            }
            rep(i,0,N){
                if(i==N-1) cout <<v[i]<<"\n";
                else cout <<v[i]<<" ";
            }
        }
        else{
            vector<int> v;
            v.pb(3);
            v.pb(9);
            v.pb(2);
            v.pb(4);
            rep(i,0,min((N-4)/2,4999)){
                v.pb(6*(i+1)+2);
                v.pb(6*(i+1)+4);
            }
            rep(i,0,max(0,min(2499,(N-4)/2-4999))){
                v.pb(12*(i+1)+3);
                v.pb(12*(i+1)+9);
            }
            rep(i,0,max(1,(N-4)-14996)){
                v.pb(6*(i+1));
            }
            rep(i,0,N){
                if(i==N-1) cout <<v[i]<<"\n";
                else cout <<v[i]<<" ";
            }
        }
    }
}