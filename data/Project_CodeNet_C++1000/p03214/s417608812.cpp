#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
  int N;
  cin >> N;
  int sum=0;
  int a[N];
  for(int i=0;i<N;i++){
    cin >> a[i];
    sum+=a[i];
  }
  int mi=1000000;
  int ans=0;
  for(int i=0;i<N;i++){
    if(abs(N*a[i]-sum)<mi){
      mi=abs(N*a[i]-sum);
      ans=i;
    }
  }
  cout << ans;
}

/*



 */

