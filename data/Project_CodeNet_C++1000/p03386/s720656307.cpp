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
  int A, B, K; cin >> A >> B >> K;
  for (int i=A;i<=B;i++){
    if (i-A<K || B-i<K) cout << i << endl;
  }

  // cout << fixed << setprecision(6);
  return 0;
}
