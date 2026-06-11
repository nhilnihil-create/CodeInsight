#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  long long k;
  cin >> a >> b >> c >> k;
  
  if (abs(b-a)>1e18){
    puts("Unfair");
  }
  else if (k==0||k%2==0){
    cout << (a-b) << endl;
  }
  else {
    cout << (b-a) << endl;
  }
}
