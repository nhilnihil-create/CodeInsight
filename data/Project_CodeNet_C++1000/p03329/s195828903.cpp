// ABC99-C
#include <bits/stdc++.h>
#define endl "\n"
#define _GLIBCXX_DEBUG //配列外参照エラー表示,gcc依存
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ipair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n;
    cin>>n;
    vector<int> coin={0,1}; //0は1を1番目にするため
    int num=6;
    while(num<=n){
        coin.emplace_back(num);
        num*=6;
    }
    num=9;
    while(num<=n){
        coin.emplace_back(num);
        num*=9;
    }
    int kind=coin.size()-1; //0が余分なため-1
    vector<vector<int>> dp(kind+10,vector<int>(n+10,n+10));
    for(int i=0;i<=kind;i++) dp[i][0]=0;
    for(int i=1;i<=kind;i++){
        for(int j=1;j<=n;j++){
            if(0<=j-coin[i]) dp[i][j]=min(dp[i][j-coin[i]]+1,dp[i-1][j]);
            else dp[i][j]=min(dp[i][j],dp[i-1][j]);
        }
    }
    cout<<dp[kind][n]<<endl;
    //cout<<coin<<endl;
    //cout<<dp<<endl;
    return 0;
}