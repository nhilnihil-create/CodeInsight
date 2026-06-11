#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int m=1000000007;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n){
    char x;
    cin >> x;
    a[i]=x-'a';
  }
  sort(a.begin(),a.end());
  a[n]=-1;
  ll ans=1;
  int now=a[0];
  int cnt=0;
  rep(i,n+1){
    if(a[i]!=now){
      ans*=cnt+1;
      ans%=m;
      now=a[i];
      cnt=1;
    }else{cnt++;}
  }
  ans--;
  ans%=m;
  cout << ans;
  return 0;
}