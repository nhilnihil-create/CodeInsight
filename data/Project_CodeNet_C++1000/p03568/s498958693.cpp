#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 int n;
  cin >> n;
  VI a(n);
  rep(i,n){
	cin >> a.at(i);
  }
  ll m;
  m=pow(3,a.size());
  int odd=1;
  rep(i,n){
    if(a.at(i)%2==0){
      odd*=2;
    }
  }
  cout << m-odd << endl;
}