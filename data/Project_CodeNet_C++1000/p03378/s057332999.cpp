#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,m,x;
  cin>>n>>m>>x;
  int right=0,left=0;
  rep(i,m){
    int a;
    cin>>a;
    if(a>x){
      right++;
    }else{
      left++;
    }
  }
  cout<<min(right,left)<<endl;
}