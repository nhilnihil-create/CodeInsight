#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  string str;
  cin >> str;
  int n = str.length();
  bool found = false;
  rep(i, n){
    for(int j=i; j<n; j++){
      string tmp = "";
      for(int k=0; k<i; k++){
        tmp += str[k];
      }
      for(int k=j; k<n; k++){
        tmp += str[k];
      }
      if(tmp == "keyence"){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
   cout << "NO" << endl;   
  return 0;
}
