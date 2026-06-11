#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<ll,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  string s; cin >> s;
  int a = 0,b = 0;
  for(int i = 0; i < 2; i++){
    a *= 10;
    a += s[i] - '0';
  }
  for(int i = 2; i < 4; i++){
    b *= 10;
    b += s[i] - '0';
  }
  if(0 < a && a <= 12){
    if(0 < b && b <= 12) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }else{
    if(0 < b && b <= 12) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }
  return 0;
}
