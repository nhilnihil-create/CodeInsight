#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n;
int a[2][105];

int change_row(int k){
  int sum=0;
  rep(i,n){
    if(i<k)sum+=a[0][i];
    else sum+=a[1][i];
  }
  return sum+a[0][k];
}

int main(){
  cin >> n;
  rep(i,2){
    rep(j,n){
      cin >> a[i][j];
    }
  }

  int max=0;
  rep(i,n){
    int tmp=change_row(i);
    if(max<tmp)max=tmp;
  }
  cout << max << endl;
}
