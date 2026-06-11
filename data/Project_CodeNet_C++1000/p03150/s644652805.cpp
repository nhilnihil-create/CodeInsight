#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

int main(){
  
  string s;
  cin >> s;
  int n = s.size();
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      string tmp = "";
      for(int k=0;k<n;k++){
        if(i<=k && k<j) continue;
        else tmp.push_back(s[k]);
      }//k
      if(tmp == "keyence"){
        cout << "YES" << endl;
        return 0;
      }
    }//j
  }//i
  cout << "NO" << endl;
}