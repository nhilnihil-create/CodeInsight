#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 10000000;
typedef pair<int,int> P;
typedef long long ll;
/*Aの累積和を取り(s[i]=Aの第i-1項までの和とする),s[i] == s[j](i>j)なら
A[j]~A[i-1]までの部分和は0になるので、

*/

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> sk(N);//Sのi文字目までの#の個数
  int count = 0;
  rep(i,N){
    if(S[i] == '#') count++;
    sk[i] = count;
  }
  

  vector<int> ss(N);//Sのi文字目までの.の個数
  int count2 = 0;
  rep(i,N){
    if(S[i] == '.') count2++;
    ss[i] = count2;
  }
  int ans = sk[N-1];
  rep(i,N){
    int res = sk[i-1] + ss[N-1]-ss[i-1];
    ans = min(res,ans);
  }
  ans = min(ans,ss[N-1]);
  cout << ans << endl;
}