#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long double ld;
typedef long long ll;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    // 累積和
    // 00010のように両端が0だったら「0個の1として」0を追加する
    // 00010の場合は03110となる
    V<int> v;
    if(s[0] == '0') v.push_back(0);
    for(int i = 0; i < n;){
        int j = i;
        while(j < n && s[j] == s[i]) j++;
        v.push_back(j - i);
        i = j;
    }
    if(s[n - 1] == '0') v.push_back(0);

    V<int> w((int)v.size() + 1, 0);
    for(int i = 0; i < (int)v.size(); i++){
        w[i + 1] = w[i] + v[i];
    }

    // 偶数番目から長さ2k+1（以下）の区間の総和のうち最大値
    // 最初が0でも上で「0個の1」を追加しているからi=0から始める
    int ans = 0;
    int m = w.size();
    for(int i = 0; i < m; i+=2){
        int j = i + k * 2 + 1;
        if(j >= m) j = m - 1;
        ans = max(ans, w[j] - w[i]);
    }
    cout << ans << endl;


    return 0;
}
