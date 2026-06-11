#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 1;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  vector<int> A(1000);
  rep(i,1001){
    if(i == 1) A[i] = i;
    else{
      A[i] = i + A[i-1]; 
    }
  }
  cout << A[b-a-1] - a << endl;
  return 0;
}