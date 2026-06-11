#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define REV(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector <string>
#define vvs vector <vector<string>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define pq  priority_queue<int>
using ll = long long;
/* ----------------よく使う数字や配列----------------- */
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
const int INF = 2000000000;
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
/* ----------------------end----------------------- */
/*---------------------template----------------------*/
/*----------------------end--------------------------*/
/* --------------------ライブラリ--------------------*/
bool isprime(ll a)//素数判定、primeならtrue,違うならfalse
{
    if (a < 2) return false;
    else if (a == 2) return true;
    else if (a % 2 == 0) return false;
    double m = sqrt(a);
    for (int i = 3; i <= m; i += 2)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    // 素数である
    return true;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ----------------------end----------------------- */
/*---------------------臨時--------------------------*/
/*----------------------end-------------------------*/
signed main(){
  string S,T;cin>>S>>T;
  sort(all(S));
  sort(T.rbegin(),T.rend());
  int minsize=min(S.size(),T.size());
  bool b=false;
  string A=S.substr(0,minsize),B=T.substr(0,minsize);
  if(A==B){
    if(S.size()<T.size())puts("Yes");
    else puts("No");
  }
  else {
    rep(i,minsize){
      if(S[i]<T[i]){
        puts("Yes");
        break;
      }
      else if(S[i]>T[i]){
        puts("No");
        break;
      }
    }
  }
}
