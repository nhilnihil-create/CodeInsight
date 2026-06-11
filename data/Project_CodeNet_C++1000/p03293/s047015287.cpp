#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  string a,b;
  cin >> a >> b;
  int c = a.size(),tmp;
  for(int i = 0;i<c;i++){
    if(a.at(0)==b.at(i)){
      tmp = i;
    for(int j = 0;j<c;j++){
      if(tmp+j>=c) tmp-=c;
      if(a.at(j)!=b.at(tmp+j)) break;
      if(j==c-1){
        cout << "Yes";
        return 0;
      }
    }
    }
  }
  cout << "No";
}