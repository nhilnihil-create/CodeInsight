#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main() {
    int n; // 参加人数
    int d; // 日数
    int x; // 残りチョコ数
    int s[101]; // s[i]: i日目に食べられたチョコ総数
    FOR(i, 1, 100) {
        s[i] = 0;
    }
    cin >> n >> d >> x;

    int tmp;
    REP(i, n) {
        cin >> tmp;
        for (int j = 1; j <= 100; j += tmp) {
            s[j] += 1;
        }
    }
    int tot = 0;
    FOR(i, 1, d) {
        tot += s[i];
    }
    cout << tot + x << endl;
    return 0;
}