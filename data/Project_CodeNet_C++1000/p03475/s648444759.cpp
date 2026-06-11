#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){os<<"("<<p.first<<","<< p.second<<")";return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v){os<<"{";REP(i,(int)v.size()){if(i)os<<",";os<<v[i];}os<<"}";return os;}
template <typename T, size_t S> void printArray(const T (&array)[S]){for(auto val : array)std::cout << val << ", ";std::cout << "\n";}
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
template<class T>inline bool chmax(T& a, T b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T& a, T b){if(a > b){a = b; return 1;}return 0;}
const ll INF = 1LL<<60;
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve(){
    ll n; cin >> n;
    vector<ll> c(n-1), s(n-1), f(n-1);
    REP(i, n-1){
        cin >> c[i] >> s[i] >> f[i];
    }
    //cout << c << endl;
    REP(i, n-1){
        ll time = c[i] + s[i];
        for(int j = i+1; j<n-1; j++){
            if(time < s[j]){
                time += (s[j] - time);
                time += c[j];
            }
            else if(time%f[j] == 0){
                time += c[j];
            }
            else{
                ll dep = s[j];
                while(dep < time){
                    dep += f[j];
                }
                time = dep;
                time += c[j];
            }
            //cout << time << endl;
        }
        cout << time << endl;
    }
    cout << 0 << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}