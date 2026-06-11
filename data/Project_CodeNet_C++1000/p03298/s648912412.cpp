#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  string x,a,b;
  cin >> x;
  a = x.substr(0, n);//この表記は重要
  b = x.substr(n, n);//
  long long ans = 0;
  map<pair<string, string>, long long > ma;
  for(int i = 0 ; i < (1<<n) ; i++){
    string red = "", blue = "";
    for(int j = 0; j < n; j++){
      if(i & (1 << j)) red += b[j];
      else blue += b[j];
    }
    reverse(red.begin(), red.end());
    reverse(blue.begin(), blue.end());
    auto p = make_pair(red, blue); //autoについて要調査
    ma[p]++;
  }

  for(int i = 0; i < (1 << n); i++){
    string red = "", blue = "";
    for(int j = 0 ; j < n; j++){
      if(i & (1 << j)) red += a[j];
      else blue += a[j];
    }
    auto p = make_pair(red, blue);
    ans += ma[p];
  }

  cout << ans << endl;
}
