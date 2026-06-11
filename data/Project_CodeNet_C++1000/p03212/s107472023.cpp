#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int dp[11][2][2][2][2][2];
int a[4]={3, 5, 7, 0};

int main(){
  string s;
  cin >> s;
  int ssz=s.size();
  dp[0][1][0][0][0][0]=1;
  rep(i, ssz){
    rep(smaller, 2){
      rep(j, 2){
        rep(k, 2){
          rep(l, 2){
            rep(m, 2){
            rep(ai, 4){
              if(ai==3 && m==1)continue;
              int ni=i+1;
              int nsmaller=smaller;
              if(smaller==1){
                if((int)(s[i]-'0')<a[ai])continue;
                if((int)(s[i]-'0')>a[ai]){
                  nsmaller=0;
                }
              }
              int nj=j, nk=k, nl=l, nm=m;
              if(j==0 && ai==0){
                nj=1;
              }
              if(k==0 && ai==1){
                nk=1;
              }
              if(l==0 && ai==2){
                nl=1;
              }
              if(m==0 && ai!=3){
                nm=1;
              }
              dp[ni][nsmaller][nj][nk][nl][nm]+=dp[i][smaller][j][k][l][m];
            }
          }
          }
        }
      }
    }
  }
  cout << dp[ssz][0][1][1][1][1]+dp[ssz][1][1][1][1][1] << endl;
  return 0;
}
