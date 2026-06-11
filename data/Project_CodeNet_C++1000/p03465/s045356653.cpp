#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const int maxs = 4e6+1;
bitset<maxs> s;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  s[0] = 1;
  ll sum = 0;
  rep(i,n){
    int x;
    cin >> x;
    sum += x;
    s |= s<<x;
  }
  ll mid = sum/2;
  for(ll i = (sum+1)/2;i<=sum; i++){
    if(s[i]){
      cout << i << endl;
      break;
    }
  }


  return 0;
    

}
