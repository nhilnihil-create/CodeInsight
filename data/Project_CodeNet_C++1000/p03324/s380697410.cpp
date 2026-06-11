#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n , d;
  cin >>d>>n;
  if(n == 100) ++n;
  while(d--){
    n *= 100;
  }
  cout<<n<<"\n";
}
