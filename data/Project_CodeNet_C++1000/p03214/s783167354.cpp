#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  double sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  sum/=n;
  double diff=1e5;
  int ans=-1;
  rep(i,n){
    if(diff>abs(sum-a[i])){
      diff=abs(sum-a[i]);
      ans=i;
    }
  }
  cout << ans << endl;
  return 0;
    

}
