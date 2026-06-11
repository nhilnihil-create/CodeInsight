#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;
int n;
string s;
bool memoo[18][18];
int memo[18][18];
string front, endd;
long long func(int len1, int len2){
    int curind = n+len1+len2;
    if (curind >= 2*n){
        return 1;
    }
    if (memoo[len1][len2]){
        return memo[len1][len2];
    }
    long long res = 0;
    if (len1 < front.size() && len2 < endd.size()){
        if (s[curind] == front[len1]){
            res += func(len1+1, len2);
        }
        if (s[curind] == endd[len2]){
            res += func(len1, len2+1);
        }
    }else if (len1 < front.size()){
        if (s[curind] == front[len1]){
            res += func(len1+1, len2);
        }
    }else{
        if (s[curind] == endd[len2]){
            res += func(len1, len2+1);
        }
    }
    memoo[len1][len2] = true;
    memo[len1][len2] = res;
    return res;
}
int main(){
  prep();
  
  cin >> n;
  cin >> s;
  int cnts[26] = {0};
  int cnts2[26] = {0};
  for (int i=0; i<n; i++){
      cnts[s[i]-'a']++;
  }
  for (int i=n; i<2*n; i++){
      cnts2[s[i]-'a']++;
  }
  for (int i=0; i<26; i++){
      if (cnts[i] != cnts2[i]){
          cout << 0;
          return 0;
      }
  }
  int poww = pow(2, n);
  long long res = 0;
  for (int i=0; i<poww; i++){
      bitset<18> bs(i);
      front = "";
      endd = "";
      for (int j=0; j<n; j++){
          if (bs[j]){
              front += s[j];
          }else{
              endd += s[j];
          }
      }
      //cout << front << " " << endd << endl;
      reverse(front.begin(), front.end());
      reverse(endd.begin(), endd.end());
      memset(memoo, false, sizeof(bool)*18*18);
      res += func(0, 0);
  }
  cout << res;
  return 0; 
}