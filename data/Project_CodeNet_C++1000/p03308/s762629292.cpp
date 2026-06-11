#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
  int n,maxv=INT_MIN,minv=INT_MAX;
  int temp;
  cin >> n;
  while(n--){
    cin >> temp;
    maxv=max(maxv,temp);
    minv=min(temp,minv);
  }
  cout << maxv-minv << endl;
}