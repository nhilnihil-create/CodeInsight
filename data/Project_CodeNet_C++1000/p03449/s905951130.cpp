#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())      //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))   //最大値を求める
#define MIN(x) *min_element(ALL(x))   //最小値を求める
//定数　
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define INTINF 1000000000
#define MOD 10000007 //10^9+7:合同式の法
#define MAXR 100000  //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first      //pairの一つ目の要素
#define S second     //pairの二つ目の要素

#define N_MAX 100
#define W_MAX 1000000000
#define v_MAX 1000

int main()
{
    int N;
    int A1_sum[N_MAX] = {};
    int A2_sum[N_MAX] = {};
    int rev_A2_sum[N_MAX] = {};
    int sum[N_MAX] = {};
    int tmp;
    int ans = 0;
    int tmpans = 0;

    cin >> N;
    cin >> A1_sum[0];
    for (int i = 1; i < N; i++)
    {
        cin >> tmp;
        A1_sum[i] = A1_sum[i - 1] + tmp;
    }
    cin >> A2_sum[0];

    for (int i = 1; i < N; i++)
    {
        cin >> tmp;
        A2_sum[i] = A2_sum[i - 1] + tmp;
    }

    rev_A2_sum[0] = A2_sum[N - 1];
    for (int i = 1; i < N; i++)
    {
        rev_A2_sum[i] = A2_sum[N - 1] - A2_sum[i - 1];
    }

    for (int i = 0; i < N; i++)
    {
        tmpans = A1_sum[i] + rev_A2_sum[i];
        if (tmpans > ans)
        {
            ans = tmpans;
        }
    }
    cout << ans;
}