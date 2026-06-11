#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  string s;
  cin >> s;

  	//数字の文字列をint型に一文字ずつ変換するラムダ式
  	auto strTOint = [&](char c){
  		return c - '0';
  	};
  	vector<int> a(s.size());
  		REP(i,s.size()){
  		a[i] = strTOint(s[i]);
  	}

  //for(auto x: a) cout << x << endl;
  int n = s.size();

  if(n == 1){
    cout << a[0] << endl;
    return 0;
  }



  for(int i = n - 1; i > 0; i--){

    //cout << "i" << i << endl;
    if(a[i] != 9 ){
      a[i] = 9;
      --a[i-1];
    }

  }

  //for(auto x: a) cout << x << endl;

  int sum = 0;
  REP(i,n) sum += a[i];
  cout << sum << endl;

  return 0;
}
