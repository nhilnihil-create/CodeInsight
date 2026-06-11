#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

//　最大値注意!!
const int MAX_N = 100000;

//　選べる仕事の中で、終了時間が最も小さいものを選ぶことを繰り返す.


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(m), t(m);
    rep(i, m) cin >> s[i] >> t[i];
    pair<int, int> itv[m];

    // pairは辞書順で比較される。
    //　終了時間が早い順にしたいため、Tをfirstに、Sをsecondに入れる。
    rep(i, m) {
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    sort(itv, itv+m);

    // timeは最後に選んだ仕事の終了時間
    int answer = 0, time = 0;
    rep(i, m) {
        if(time <= itv[i].second) {
            answer++;
            time = itv[i].first;
        }
    }

    cout << answer << endl;
}