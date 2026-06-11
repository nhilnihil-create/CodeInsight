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

vector<int> solve(int N){
    vector<int> res(100,0);
    for(int i = 1; i < N+1; i++){
        int now = i;
        for(int j = 2; j < N+1; j++){
            if(now % j != 0) continue;
            int cnt = 0;
            while(now % j == 0){
                cnt++;
                now /= j;
            }
            res[j] += cnt;
        }
        if(now != 1) res[now] += 1;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    vector<int> res(100);
    res = solve(N);
    int ans = 0;
    int cnt_25 = 0;
    int cnt_15 = 0;
    int cnt_5 = 0;
    int cnt_3 = 0;
    rep(i,100){
        if(res[i] >= 74) ans++;
        if(res[i] >= 24){
            cnt_25++;
            cnt_15++;
            cnt_5++;
            cnt_3++;
        }
        else if(res[i] >= 14){
            cnt_15++;
            cnt_5++;
            cnt_3++;
        }
        else if(res[i] >= 4){
            cnt_5++;
            cnt_3++;
        }
        else if(res[i] >= 2) cnt_3++;
    }
    ans += cnt_25*(cnt_3-1);
    ans += cnt_15*(cnt_5-1);
    ans += cnt_5*(cnt_5-1)/2*(cnt_3-2);
    cout << ans << endl;
}