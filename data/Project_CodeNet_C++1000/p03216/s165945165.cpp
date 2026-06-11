#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#define BIT(nr) (1ULL << (nr))
#define int long long
//#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }


using namespace std;

int cumM[2000000];
int cumC[2000000];
int N, Q;
string S;

int solve(int k) {
    int ans = 0;
    int left = -1, right = -1;
    REPS(i, N) {
        if (S[i] == 'D') {
            left = i;
            break;
        }
    }
    //Dがない
    if (left == -1) {
        return 0;
    }
    //しゃくとり
    int calcSum = 0;
    right = left + 1;
    while (left <= N) {
        while (right <= N && right - left < k) {
            //Cが見つかったらleft のD, right のCでつくれるDMCを加算
            if (S[right] == 'C') {
                calcSum += cumM[right] - cumM[left - 1];
            }
            right++;
        }

        ans += calcSum;

        //left を動かす
        int oldLeft = left;
        left++;
        while (left <= N && S[left] != 'D') {
            //Mが見つかったらoldLeftのD、rightまでにあるC でつくれるDMCを減算(rightは条件を満たすright + 1になっていることに注意)
            if (S[left] == 'M') {
                calcSum -= cumC[right-1] - cumC[left - 1];
            }
            left++;
        }
    }
    return ans;

}

signed main() {
    cin >> N >> S >> Q;
    S = "*" + S + "*";
    vector<int> querys(Q);
    rep(i, Q) {
        cin >> querys[i];
    }
    int mCou = 0;
    int cCou = 0;

    //累積和
    REPS(i, N+1) {
        if (S[i] == 'M') {
            mCou++;
        }
        if (S[i] == 'C') {
            cCou++;
        }
        cumC[i] = cCou;
        cumM[i] = mCou;
    }

    for (int i : querys) {
        cout << solve(i) << "\n";
    }


    return 0;
}
