#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  vi warikiru;
  for(int i = 1; i<a+b; i++){
    if(a%i == 0 && b%i == 0) warikiru.push_back(i);
  }
  sort(warikiru.rbegin(),warikiru.rend());
  cout << warikiru[k-1] << endl;
}
