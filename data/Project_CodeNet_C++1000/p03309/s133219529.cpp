#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll i,n,a[200010];
  cin >> n;
  vector<ll> x;
  for(i=0;i<n;i++){
    cin >> a[i];
    x.push_back(a[i]-i-1);
  }
  sort(x.begin(),x.end());
  ll sum=0,ans=x[n/2];
  for(i=0;i<n;i++){
    sum+=abs(x[i]-ans);
  }
  cout << sum << endl;
}