#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  int a[10];
  int all = 1, bad = 1;
  rep(i,n){
    scanf("%d", a+i);
    all *= 3;
    if(a[i]%2==0) bad*=2;
  }
  cout << all - bad << endl;
  return 0;
}