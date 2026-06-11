#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;

const int MAX = 55556;


int main(){
    
    int N; cin >> N;
    vector<int> is_prime(MAX, true);
    // エラトステネスのふるい
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; i++){
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = false;
    }

    vector<int> ans;

    // 素数を列挙
    rep(i, MAX){
        if (is_prime[i]) {
            if (i % 5 == 1){
                ans.push_back(i);
                if (ans.size() == N) break;
            }
        }
    }

    rep(i, ans.size()){
        printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
    }
}