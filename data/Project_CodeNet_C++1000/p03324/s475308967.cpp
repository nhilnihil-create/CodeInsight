#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll d,n,p=1;
  cin >> d >> n;
  for(int i=0;i<d;i++){
    p*=100;
  }
  if(n==100){
    n++;
  }
  if(d==0){
    cout << n;
  }else{
    cout << p*n;
  }
}
    