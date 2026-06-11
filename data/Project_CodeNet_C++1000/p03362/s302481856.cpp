#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;


const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

vector<bool> prime_table(int n)
{
    vector<bool> prime(n + 1, true);
    if (n >= 0)
        prime[0] = false;
    if (n >= 1)
        prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i + i; j <= n; j += i)
        {
            prime[j] = false;
        }
    }
    return prime;
}
int main()
{
    vector<bool> table=prime_table(55555);
    int n;
    cin >> n;
    int now=2;
    vector<int> ans;
    while(n>0){
        if(table[now]&&now%5==1){
            ans.push_back(now);
            n--;
        }
        now++;
    }
    REP(i,ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
}
