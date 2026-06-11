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

int main() {
ll n;
cin>>n;
ll ans[101];
ans[0] = 2;
ans[1] = 1;
for(int i = 2; i < 100; i++ ){
    ans[i] = ans[i-1] + ans[i-2];
}

cout<<ans[n]<<endl;
   return 0;
}
