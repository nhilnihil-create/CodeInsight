#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

int main(){
    string s, t;
    cin >> s >> t;
    vector<vector<ll>> dp(s.size()+3, vector<ll>(t.size()+3, 0));
    dp.at(0).at(0) = 0;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if (s.at(i-1) == t.at(j-1)){
                dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
            }
            else{
                dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
            }
        }
    }
    int len = dp.at(s.size()).at(t.size());
    int i = s.size();
    int j = t.size();
    string ans = "";
    while(len > 0){
        if (s.at(i-1) == t.at(j-1)){
            ans = s.at(i-1) + ans;
            i--;
            j--;
            len--;
        }
        else if(dp.at(i).at(j) == dp.at(i-1).at(j)){
            i--;
        }
        else{
            j--;
        }
    }
    cout << ans << endl;
}
