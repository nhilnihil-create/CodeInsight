#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> height;
    int k;
  for(int i=0;i<n;i++){
    cin>>k;
    height.push_back(k);
  }
  vector<int> X(n,0);
  X[1]=abs(height[0]-height[1]);
  for(int i=2;i<n;i++){
    X[i]=min(X[i-1]+abs(height[i]-height[i-1]),X[i-2]+abs(height[i]-height[i-2]));
  }
  cout<<X[n-1]<<"\n";
}