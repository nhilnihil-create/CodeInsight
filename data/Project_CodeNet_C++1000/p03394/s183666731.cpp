#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


void solve(){
    int N;
    cin >> N;
    if(N == 3){
        cout << "2 5 63" << endl;
        return;
    }
    else if(N == 4){
        cout << "2 5 20 63" << endl;
        return;
    }
    else if(N == 5){
        cout << "2 5 20 30 63" << endl;
        return;
    }
    ll sum = 0;
    vector<int> ans;
    int k = 0;
    while(N > 0){
        if(N > 0){
            ans.push_back(6*k + 2);
            N--;
            sum += 6*k + 2;
        }
        if(N > 0){
            ans.push_back(6*k + 3);
            N--;
            sum += 6*k + 3;
        }
        if(N > 0){
            ans.push_back(6*k + 4);
            N--;
            sum += 6*k + 4;
        }
        if(N > 0){
            ans.push_back(6*k + 6);
            N--;
            sum += 6*k + 6;
        }
        k++;
    }
    cerr << sum << endl;
    if(sum % 6 == 2){
        auto itr = lower_bound(ans.begin(), ans.end(), 8);
        ans.erase(itr);
        for(int i=3e4;i>ans.back();i--) if(i % 6 == 0){
            ans.emplace_back(i);
            break;
        }
    }
    if(sum % 6 == 3){
        auto itr = lower_bound(ans.begin(), ans.end(), 9);
        ans.erase(itr);
        for(int i=3e4;i>ans.back();i--) if(i % 6 == 0){
            ans.emplace_back(i);
            break;
        }
    }
    if(sum % 6 == 5){
        auto itr = lower_bound(ans.begin(), ans.end(), 9);
        ans.erase(itr);
        for(int i=3e4;i>ans.back();i--) if(i % 6 == 4){
            ans.emplace_back(i);
            break;
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}
