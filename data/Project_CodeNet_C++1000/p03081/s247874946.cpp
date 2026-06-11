#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

bool solve1(int mid, int N, int Q, string s, vector<char> &t, vector<char> &d){
    char now = s[mid];
    rep(i,Q){
        if(t[i] == now){
            if(d[i] == 'L'){
                mid--;
                if(mid < 0) return false;
                now = s[mid];
            }
            else{
                mid++;
                if(mid >= N) return true;
                now = s[mid];
            }
        }
    }
    return true;
}

bool solve2(int mid, int N, int Q, string s, vector<char> &t, vector<char> &d){
    char now = s[mid];
    rep(i,Q){
        if(t[i] == now){
            if(d[i] == 'L'){
                mid--;
                if(mid < 0) return true;
                now = s[mid];
            }
            else{
                mid++;
                if(mid >= N) return false;
                now = s[mid];
            }
        }
    }
    return true;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    string s; 
    cin >> s;
    vector<char> t(Q), d(Q);
    rep(i,Q) cin >> t[i] >> d[i];
    int ans = N;

    ll left = -1;
    ll right = N;
    while(right - left > 1){
        ll mid = (left + right) / 2;
        if(solve1(mid, N, Q, s, t, d)) right = mid;
        else left = mid;
    }
    ans -= right;
    left = -1;
    right = N;
    while(right - left > 1){
        ll mid = (left + right) / 2;
        if(solve2(mid, N, Q, s, t, d)) left = mid;
        else right = mid;
    }
    ans -= N-1-left;
    cout << ans << endl;
}