#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  int N = 0,M = 0,X = 0,ans1 = 0,ans2 = 0;
  cin >> N >> M >> X;
  vector<int>A(M);
  rep(i,M){
    cin >> A[i];
    if(A[i] > X){
      ans1++;
    }
    else{
      ans2++;
    }
  }
  cout << min(ans1,ans2);
}
  