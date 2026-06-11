#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 1e9+7;

/*bool empty_pq(priority_queue<int> &R){
  if(R.size()==0) return true;
  else return false;
}*/

int main(){
  int n;
  int64_t ab;
  cin >> n;
  vector<int64_t> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  priority_queue<int> R;
  //int rest=0;
  int64_t count = 0, ans=0, sum=0;
  rep(i, n){
    if(B[i]<A[i]){
      ab = A[i]-B[i];
      R.push(ab);
      count++;
    }
    else if(A[i]==B[i])  count++;
    else {
      ans++;
      sum += B[i]-A[i];
    }
  }
  //cout << count << endl;
  if(count==n) cout << 0 << endl; 
  else{
  int64_t q;  
  /*q = R.top();
  R.pop();
  ans++;*/  
  rep(i, n){
  q = R.top();
  R.pop();
  ans++;  
  sum -= q;
  if(sum<=0) break;
  else if(R.size()==0){
    ans = -1;
    break;
  } 
  }  
   cout << ans << endl; 
  }
}