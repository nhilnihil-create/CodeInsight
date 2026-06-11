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
  string S, T; cin >> S >> T;
  
  int s = 0;
  bool flag = false;
  while (true){
    s = S.find(T[0], s);
    if (s==-1) break;

    if (S.substr(s)+S.substr(0,s) == T){
      flag = true;
      break;
    }
    s++;

  }

  cout << (flag? "Yes" : "No") << endl;

  // cout << fixed << setprecision(6);
  return 0;
}

