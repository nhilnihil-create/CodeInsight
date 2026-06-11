#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, sum=0;
  string n;
  cin >> a >> b;
  
  for(int i=a; i <= b; i++){
    n = to_string(i);
    if((n[0] == n[4]) && (n[1] == n[3])) sum++;
  }
  
  cout << sum << endl;
}
