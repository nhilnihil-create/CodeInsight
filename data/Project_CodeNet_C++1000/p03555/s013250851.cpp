#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string str1, str2;
  cin >> str1 >> str2;

  if (str1.at(0) == str2.at(2) && str1.at(1) == str2.at(1) && str1.at(2) == str2.at(0)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
