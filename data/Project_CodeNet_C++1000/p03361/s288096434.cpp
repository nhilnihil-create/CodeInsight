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
 int h,w;cin>>h>>w;
 string s[h];
 rep(i,h){
     cin>>s[i];
 }
 int A[] = {1,0,-1,0};
 int B[] = {0,-1,0,1};

 rep(i,h){
     rep(j,w){
        // cout<<s[i][j]<<endl;
         if(s[i][j] == '.') continue;
         bool flag=false;
         rep(g,4){
             if(i+A[g] == -1 || i+A[g] == h||j+B[g] == -1 || j+B[g] == w) continue;
                if(s[i+A[g]][j+B[g]] == '#') flag = true; 
         }
         if(!flag){
             cout<<"No"<<endl;
             return 0;
         }
     }
 }
cout<<"Yes"<<endl;
    return 0;
}
