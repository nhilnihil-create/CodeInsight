#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
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
ll gcd (ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    rep(i,0,T){
        ll A,B,C,D;
        cin>>A>>B>>C>>D;
        ll g=gcd(B+D,B);
        ll t;
        if(A<B){
            cout <<"No"<<"\n";
            continue;
        }
        if(B>D){
            cout <<"No"<<"\n";
            continue;
        }
        if(A%B>C){
            cout <<"No"<<"\n";
            continue;
        }
        if(B==D){
            cout <<"Yes"<<"\n";
            continue;
        }
        if(A>=-B+C+1){
            t=A%B-(-B+C+1)%B;
            t=(t+B)%B;
        }
        else{
            t=A%(D-B)-(-B+C+1)%(D-B);
            t=(t+D-B)%(D-B);
        }
        if(t-g*(t/g)-B+C+1>=0) cout <<"Yes"<<"\n";
        else cout <<"No"<<"\n";
    }
}