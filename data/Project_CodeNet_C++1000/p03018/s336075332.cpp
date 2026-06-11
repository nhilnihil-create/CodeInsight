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
  string newStr = "";
  rep(i, n){
    if(str[i] == 'A'){
      newStr += 'A';
    }else if(str[i] == 'B'){
      if(i != n-1 && str[i+1] == 'C'){
        newStr += 'D';
        i++;
      }else{
        newStr += 'B';
      }
    }else{
      newStr += 'C';
    }
  }
  int a = 0;
  ll cnt = 0;
  rep(i, newStr.length()){
    if(newStr[i] == 'A') a++;
    else if(newStr[i] == 'D') cnt += a;
    else a = 0;
  }
  cout << cnt << endl;
  return 0;
}
  
  