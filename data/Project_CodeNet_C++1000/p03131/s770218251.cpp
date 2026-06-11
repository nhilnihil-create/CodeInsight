#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  ll K, A, B; cin >> K >> A >> B;
  if (B-A<=2) cout << K+1 << endl;
  else {
    if (K<=A) cout << K+1 << endl;
    else if ((K-A)%2) cout << ((K-A)/2)*(B-A) + B << endl;
    else cout << ((K-A)/2-1)*(B-A) + B +1 << endl;
  }
  // cout << fixed << setprecision(10);
  
  return 0;
}

