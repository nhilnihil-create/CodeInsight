#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define all(x) x.begin(),x.end()
#define mod 1000000007

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin>>n;
  ll ans=0;
  for(int i=0;i<n;i++){
    int x; cin>>x;
    ans+=x;
  }
  cout<<ans-n<<"\n";
  return 0;
}