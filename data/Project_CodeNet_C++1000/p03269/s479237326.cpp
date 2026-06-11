#include<algorithm>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << endl

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-8;

constexpr int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
constexpr int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct edge{
    int from, to, cost;
};

template<typename T>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int l;
    cin >> l;

    vector<edge> ans;
    int maxi = 0;
    rep(i, 19){
        ans.push_back({i, i + 1, 0});
        if((1 << (i + 1)) <= l){
            ans.push_back({i, i + 1, 1 << i});
            chmax(maxi, (1 << (i + 1)) - 1);
        }
    }

    rrep(i, 19){
        if((1 << i) < l - 1 && l - (1 << i) > maxi){
            ans.push_back({i, 19, l - (1 << i)});
            l -= (1 << i);
        }
    }

    cout << 20 << " " << ans.size() << endl;
    for(auto e : ans){
        cout << e.from + 1 << " " << e.to + 1 << " " << e.cost << endl;
    }

    return 0;
}