#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
//sを繋げて新たな"AB"ができるのは末尾がAの文字列と先頭がBの文字列を繋げた場合で、
/*
*/

int main() {
   int N;
   cin >> N;
   vector<string> s(N);
   rep(i,N){
       cin >> s[i];
   }

   int cAB = 0;//(B,A)型の数
   int cA = 0;//(0,A)型の数
   int cB = 0;//(B,0)型の数
   rep(i,N){
       if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') cAB++;
       if(s[i][0] != 'B' && s[i][s[i].size()-1] == 'A') cA++;
       if(s[i][0] == 'B' && s[i][s[i].size()-1] != 'A') cB++;
   }
   ll ans = 0;
   //各sの内側にある"AB"の個数をカウント
   for(int i = 0;i<N;i++){
       for(int j = 0;j<s[i].size()-1;j++){
           if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
       }
   }
  // cout << ans << endl;

   if(cA == 0 && cB == 0){
       ans += max(cAB-1,0);
   }
  else ans += (cAB + min(cA,cB));


   cout << ans << endl;
   //cout << cAB << " " << cA << " " << cB << endl;
 }