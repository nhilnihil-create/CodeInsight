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
int n; cin>>n;
string s; cin>>s;
//入力
int ans = 0;
rep(i,s.size()){
    string dy1 = s,dy2 = s;
    int count = 0;
    map<char,bool> m;
    dy1.erase(i);//i番目移行の文字を消去
    dy2 = dy2.substr(i);//i番目以降を取り出す
    //cout<<dy1<<" "<<dy2<<endl;
    rep(j,dy1.size()){
        m[dy1[j]] =true;
    }//dy1に含まれる文字種類
    rep(j,dy2.size()){
        if(m[dy2[j]]) {
            count++;//両方にいる
        m[dy2[j]] = false;//同じ文字は無し
        }
    }//dy2にもいるかどうか
ans = max(ans,count);//最大数
}//分割したもの全部調べる
cout<<ans<<endl;
    return 0;
}
