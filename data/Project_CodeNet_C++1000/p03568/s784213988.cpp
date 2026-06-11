#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a=1,b=1;
  for(int i=0;i<n;i++){
    a*=3;
    int x;
    cin >> x;
    if(x%2==0) b*=2;
  }
  cout << a-b << endl;
}