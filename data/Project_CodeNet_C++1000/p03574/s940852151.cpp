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
int h,w; cin>>h>>w;
string s[h];
rep(i,h)cin >>s[i];
//入力
int A[] = {1,1,1,0,0,-1,-1,-1};
int B[] = {1,0,-1,1,-1,1,0,-1};//回りまわす配列

rep(i,h){
    rep(j,w){
        if(s[i][j] == '#') continue;//爆弾は無視
        int count = 0; 
        rep(a,8){
            if(i+A[a] == -1||i+A[a] == h|| j+B[a] == -1||j+B[a]==w) continue;//グラフより外は無視
           if(s[i+A[a]][j+B[a]] == '#') count++;//爆弾の数数える
            
        }//8マス周りをまわる
        s[i][j] = '0' + count;//爆弾の数を入れる

    }
}//全部のマスを調べる

rep(i,h){
    cout<<s[i]<<endl;
}

    return 0;
}
