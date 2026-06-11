#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  int n;
  cin >>n;
  int a[n],b[n];
  rep(i,n){
    cin >> a[i];
    b[i]=a[i];
  }
  sort(b,b+n);
  rep(i,n){
    if(a[i]>=b[n/2]){cout << b[n/2-1] << endl;}else{cout << b[n/2] << endl;}
  }
}