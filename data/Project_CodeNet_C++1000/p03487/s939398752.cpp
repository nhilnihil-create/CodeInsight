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

int main(){
int n;
cin>>n;
ll a[n];
map<ll,int> m;
rep(i,n){
    cin>>a[i];
    m[a[i]]++;
}
ll count = 0;
rep(i,n){
    if(a[i]<m[a[i]]) {
        m[a[i]]--;
        count++;
    }else if(a[i]>m[a[i]]){
        count++;
    }


}cout<<count<<endl;
    return 0;
}