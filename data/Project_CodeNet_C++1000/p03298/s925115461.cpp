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
unordered_map<string, long long> mp[19];
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
      string front = "";
      string endd = "";
      for (int j=0; j<n; j++){
          if (bs[j]){
              front += s[j];
          }else{
              endd += s[j];
          }
      }
      //cout << front << " " << endd << endl;
      reverse(endd.begin(), endd.end());
      for (int i=0; i<endd.size(); i++){
          front += endd[i];
      }
      reverse(front.begin(), front.end());
      mp[bs.count()][front]++;
  }
  for (int i=0; i<poww; i++){
      bitset<18> bs(i);
      string front = "";
      string endd = "";
      for (int j=n; j<2*n; j++){
          if (bs[j-n]){
              front += s[j];
          }else{
              endd += s[j];
          }
      }
      //cout << front << " " << endd << endl;
      reverse(endd.begin(), endd.end());
      for (int i=0; i<front.size(); i++){
          endd += front[i];
      }
      auto val = mp[bs.count()].find(endd);
      if (val != mp[bs.count()].end()){
          res += val->second;
      }
      
  }
  cout << res;
  return 0; 
}
