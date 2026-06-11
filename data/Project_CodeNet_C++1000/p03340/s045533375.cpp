#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

int main() {
  int n; cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];
  
  ll res=0,sum=0;
  int r=0;
  rep(l, n) {
    while (r<n&&(sum^a[r])==(sum+a[r])) {
      sum+=a[r];
      ++r;
    }
    res+=r-l;
    if (r==l) r++;
    else sum-=a[l];
  }
  cout<<res<<endl;
}