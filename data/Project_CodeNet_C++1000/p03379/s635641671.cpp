#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i;
  cin >> n;
  vector<int> x(n),y(n);
  
  for(i=0;i<n;i++){
    cin >> x.at(i);
    y.at(i)=x.at(i);
  }
  
  sort(y.begin(),y.end());
  for(i=0;i<n;i++){
    if(x.at(i)<=y.at(n/2-1)){
      cout << y.at(n/2) << endl;
    }else{
      cout << y.at(n/2-1) << endl;
    }
  }
}