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
    ll k,a,b;
    cin>>k>>a>>b;
    ll ans = 1;
    if(b - a <=2 || k + 1 <= a){
        ans += k;
    }else
    {
        ans += a - 1;
        k -= a - 1;

        ans += (b - a) * (k/2) + k%2;
    }
    
cout<<ans<<endl;

    return 0;
}
