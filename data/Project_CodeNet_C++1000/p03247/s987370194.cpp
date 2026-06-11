#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for(int i = 0; i < N;i++)cin >> X[i] >> Y[i];
    int wa = abs(X[0])+abs(Y[0]);
    for(int i = 0; i < N;i++){
        if(wa%2 != (abs(X[i])+abs(Y[i]))%2){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<ll> d;

    for(int s = 32;s >= 0;s--){
        d.push_back(bit(s));
    }
    if((X[0]+Y[0])%2 == 0){
        d.push_back(1);
    }
    cout << d.size() << endl;
    rep(i,d.size()){
        cout << d[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        string ans = "";
        ll u = X[i] + Y[i];
        ll v = X[i] - Y[i];
        ll nx = 0;
        ll ny = 0;
        for(int j = 0; j < d.size();j++){
            //目的地まで+にしたい
            if(nx <= u){
                nx += d[j];
                if(ny <= v){
                    ny += d[j];
                    ans.push_back('R');
                }
                else{
                    ny -= d[j];
                    ans.push_back('U');
                }
            }
            else{
                nx -= d[j];
                if(ny <= v){
                    ny += d[j];
                    ans.push_back('D');
                }
                else{
                    ny -= d[j];
                    ans.push_back('L');
                }
            }
        }
        ll mx = 0;
        ll my = 0;
        for(int i = 0; i < d.size();i++){
            if(ans[i] == 'R')mx += d[i];
            if(ans[i] == 'L')mx -= d[i];
            if(ans[i] == 'U')my += d[i];
            if(ans[i] == 'D')my -= d[i];
        }
        cout << ans << endl;
    }
}