#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n;
  cin>>n;
  vector<ll>v(n+2);
  v[0] = 0;
  for(int i=0; i<n; i++) {cin >> v[i+1];}
  v[n+1] = 0;
  ll sum=0;
  for(int i=1; i<n+2; i++){
    sum += abs(v[i]-v[i-1]);
  }
  for(int i=1; i<n+1; i++){
    cout << sum - abs(v[i]-v[i-1]) - abs(v[i+1]-v[i]) + abs(v[i+1]-v[i-1]) << endl;
  }
return 0;
}


