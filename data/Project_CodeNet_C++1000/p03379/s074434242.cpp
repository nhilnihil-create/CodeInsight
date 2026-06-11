#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int>x(n);
  for(int i=0;i<n;i++){
    cin >> x.at(i);
  }
  vector<int>copy(n);
  copy=x;
  sort(copy.begin(),copy.end());
  for(int i=0;i<n;i++){
    if(x.at(i)>=copy.at(n/2)){
      cout << copy.at((n/2)-1) << endl;
    }
    else{
      cout << copy.at(n/2) << endl;
    }
  }
}