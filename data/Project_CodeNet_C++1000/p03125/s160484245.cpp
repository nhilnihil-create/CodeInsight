#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define debug(x)      cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl
#define debugvec(v)   rep(i, v.size()) cerr << "L" << __LINE__ << ": " << #v << "[" << i << "] = " << v[i] << endl;
#define debugvec2(v)  cerr << "L" << __LINE__ << ": " << #v << " = { "; rep(i, v.size()) cerr << v[i] << (i + 1 == v.size() ? "" : ", "); cerr << " }" << endl;
typedef long long ll;  /* 10^18 くらいまでいける */

vector<int> getYakusuu(int a){
  vector<int> Yakusuu;
  for(int i=1; i<=a; i++){
    if (a%i==0)
      Yakusuu.push_back(i);
  }
  return Yakusuu;
}

int main(){
  int a, b;
  cin >> a >> b;

  auto yakusuu = getYakusuu(b);

  bool flag = false;
  rep(i, yakusuu.size()){
    if (yakusuu[i] == a){
      flag=true;
      break;
    }
  }
  if(flag){
    cout << a+b << endl;
  }else{
    cout << b-a << endl;
  }

  return 0;
}