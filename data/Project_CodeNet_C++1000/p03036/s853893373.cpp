#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll r,d,x;
  cin >> r >> d >> x;
  ll y[11];
  y[0]=x;
  for(int i=0;i<10;i++){
    y[i+1]=r*y[i]-d;
    cout << y[i+1] << endl;
  }

}