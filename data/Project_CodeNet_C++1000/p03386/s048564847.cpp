#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  int A, B, K; cin >> A >> B >> K;
  int count=0;
  int chkA = 0;
  for(int i=A; i<=B; i++){
    count++;
    cout << i << endl;
    if(i==B) return 0;
    if(count == K){chkA = i; break;}
  }
  count = 0;
  int chkB = 0;
  
  for(int i=B; i>=A; i--){
    if(i==chkA) {chkB = i+1; break;}
    count++;
    if(count == K) {chkB = i; break;}
  }
  for(int i=chkB; i<=B; i++){
    cout << i << endl;
  }
  
}