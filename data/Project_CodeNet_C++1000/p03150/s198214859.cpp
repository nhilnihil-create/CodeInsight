#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string S; cin >> S;
  string k = "keyence";
  
  bool flag = false;
  rep(i,S.size()){
    for (int j=i;j<S.size();j++){
      string s = S.substr(0,i) + S.substr(j);
      if (s==k) flag = true;
    }
  }
  cout << (flag? "YES" : "NO") << endl;

  // cout << fixed << setprecision(6);
  return 0;
}

