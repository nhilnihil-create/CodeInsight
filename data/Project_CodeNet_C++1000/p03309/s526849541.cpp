#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
    a[i]-=i;
  }
  ll res=0;
  ll res2=0;
  vector<int> b(n);
  rep(i,n) b[i]=a[i];
  sort(b.begin(),b.end());
  int p=b.size()/2;
  int q=p-1;
  rep(i,n){
    res+=abs(a[i]-b[p]);
    res2+=abs(a[i]-b[q]);
  }
  cout<<min(res,res2)<<endl;
}