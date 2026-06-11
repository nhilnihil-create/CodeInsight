#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
string s; cin>>s;//入力
ll count=0,ans=0;
rep(i,s.size()){
    if(s[i] == 'B') count++;
    else
    {
        ans += count;
    }//Wより右にあるBの数を数える
    
}
cout<<ans<<endl;
    return 0;
}
