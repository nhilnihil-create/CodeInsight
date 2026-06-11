#include<bits/stdc++.h>
using namespace std;

int main(){
  int k;
  
  cin >> k;
  
  if(k%2==1)
    cout << (k+1)/2 * (k-1)/2 << endl;
  else
    cout << pow(k/2,2) << endl;
    
}