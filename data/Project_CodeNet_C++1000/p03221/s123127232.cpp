#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
struct edge{ll to, cost;};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define INF 1000000000000
#define ALL(a)  (a).begin(),(a).end()

std::string rsubstr(std::string str, size_t pos, size_t len = std::string::npos)
{
    // 元の文字列の長さを取得します。
    const size_t strlen = str.length();

    // 切り出す文字列の長さが省略された、または切り出し開始位置+1より長い場合
    if ((std::string::npos == len) || ((pos + 1) < len))
    {
        // 切り出す文字列の長さを文字列の末尾までに変更します。
        len = pos + 1;
    }

    // 文字列を切り出します。
    std::string dst = str.substr(strlen - pos - 1, len);
    return dst;
}


int main(){
    ll n,m;
    cin >> n >> m;
    ll p[100000],y[100000];
    vector<ll> hoge[100001];
    for(ll i = 0; i < m; i++){
        ll temp1,temp2;
        cin >> temp1 >> temp2;
        p[i] = temp1;
        y[i] = temp2;
        hoge[p[i]].push_back(y[i]);
    }
    for(int i=1; i <= n ; i++){
        sort(hoge[i].begin(),hoge[i].end());
    }
    for(int i = 0; i < m; i++){
        string  pre = "000000"+to_string(p[i]);
        auto iter = lower_bound(ALL(hoge[p[i]]),y[i]);
        string city = "000000"+to_string(iter-hoge[p[i]].begin()+1);
        cout << rsubstr(pre,5) << rsubstr(city,5) << endl;

    }

}