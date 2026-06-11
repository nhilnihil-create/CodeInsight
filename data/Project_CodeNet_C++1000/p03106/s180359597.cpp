#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,k;
  cin>>a>>b>>k;
  int count=0;
  int c=max(a,b);
  vector<int> x;
  for(int i=1;i<=c;i++){
    if(a%i==0&&b%i==0){
      x.push_back(i);
      count++;
    }
  }
  reverse(x.begin(),x.end());
  cout<<x[k-1]<<endl;
}