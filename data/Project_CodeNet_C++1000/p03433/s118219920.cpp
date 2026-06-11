#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,n_new,a,b,ans;
  cin >> n >> a;
  
  b = n/500;
  n_new = n - b*500;
  ans = n_new - a;
  if(ans <= 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
