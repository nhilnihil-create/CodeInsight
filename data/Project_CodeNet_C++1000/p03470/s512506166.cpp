#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n;
  x=0;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  for(int i=0; i<n-1; i++){
    if(v[i]==v[i+1]){
      x++;
    }
  }
  cout<<v.size()-x<<endl;
}