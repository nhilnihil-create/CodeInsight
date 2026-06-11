#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int n;
  ll min = pow(10, 9), max = 0;
  cin >> n;
  rep(i, n){
    int a;
    cin >> a;
    if(min > a){
      min = a;
    }
    if(max < a){
      max = a;
    }
  }
  cout << max - min << endl;
}