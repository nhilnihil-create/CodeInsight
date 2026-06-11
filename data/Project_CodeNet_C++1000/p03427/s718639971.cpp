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
  ll N, N0; cin >> N;
  N0 = N;
  vector<int> digit;
  int dsum = 0;
  while (N0>0){
    digit.push_back(N0%10);
    dsum += N0%10;
    N0 /= 10;
  }

  if (digit.size()==1) cout << N << endl;
  else cout << max(dsum, digit[digit.size()-1]-1 + 9*((int)digit.size()-1)) << endl;




  

  // cout << fixed << setprecision(6);
  return 0;
}

