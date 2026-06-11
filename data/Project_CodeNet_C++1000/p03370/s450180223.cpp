#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include<set> 
#include<math.h>
#define pai arccos(-1);
#define keta(n) cout << fixed << setprecision((n));
#define ll long long;

int main() {
  int mn = 1e9;
	int n,x;
  cin>>n>>x;
  vector<int> m(n);
  rep(i,n){
    cin>>m[i];
  }
  int sum=0;
  rep(i,n){
    sum += m[i];
  }
  rep(i,n){
    mn = min(mn,m[i]);
  }
  
  int count = (x-sum)/mn;
  cout<<n+count<<endl;
	}
