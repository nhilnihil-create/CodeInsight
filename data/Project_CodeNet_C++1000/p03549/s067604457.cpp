#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 999999999
const int mod = 1000000007;
ll cnt = 0;
 
int main(){
  ll n,m; cin >> n >> m;
  cout << (1900*m+100*(n-m))*pow(2,m) << endl;
}