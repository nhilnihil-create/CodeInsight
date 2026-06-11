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
ll a[n];
ll count =0;
rep(i,n){
    cin>>a[i];
    if(a[i] % 2 == 0)count++;
}
    cout<<pow(3,n) - pow(2,count)<<endl;





   return 0;
}
