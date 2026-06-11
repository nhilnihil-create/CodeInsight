#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

void solve(){
    ll d,g;
    cin >> d >> g;
    g /= 100;
    Vi p(d),c(d);
    rp(i,d) {
        cin >> p.at(i) >> c.at(i);
        c.at(i)/=100;
    }
    ll ans=INF;
    rp(mask,(1<<d)){
        ll rem=g;
        ll ctr=0;
        rp(i,d){
            if(mask&(1ll<<i)){
                rem-=c[i];
                rem-=(i+1)*p[i];
                ctr+=p[i];
            }
        }
        //if(mask==2)print(rem);
        if(rem<=0) chmin(ans,ctr);
        else{
            for(ll i=d-1; i>=0; i--){
                //if(mask==2) print(mask&(1ll<<i));
                if(mask&(1ll<<i)){}else{
                    //if(mask==2) print(i);
                    if(rem-(i+1)*(p[i]-1)<=0){
                        //if(mask==2) print("here");
                        ctr+=(rem+i)/(i+1);
                        rem=0;
                        break;
                    }
                    else{
                        ctr+=p[i]-1;
                        rem-=(i+1)*(p[i]-1);
                    }
                }
            }
            if(rem<=0)chmin(ans,ctr);
        }
    }
    print(ans);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}