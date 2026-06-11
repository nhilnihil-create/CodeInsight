#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,k;
  cin >> n >> k;
  int num = 1;
  rep(i,n){
    if(2*num >= num+k) num += k;
    if(2*num < num+k)  num *= 2;
  }
  cout << num << endl;
}