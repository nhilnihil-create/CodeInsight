#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define pr pair<int,int>
#define all(x) x.begin(),x.end()
#define mod 1000000007

int main(){
  ios_base::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
  int n; cin>>n;
  vector<int> a(n),b(n);
  ll sum1=0,sum2=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum1+=a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
    sum2+=b[i];
  }

  // sort(all(a));
  // sort(all(b));
  ll opr=0;
  for(int i=0;i<n;i++){
    if(a[i]<b[i]){
      opr+=(b[i]-a[i])/2+(b[i]-a[i])%2;
    }
  }
  if(opr<=(sum2-sum1)){
    cout<<"Yes\n";
  }
  else
    cout<<"No\n";
  return 0;
}