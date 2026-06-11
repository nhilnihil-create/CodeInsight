#include<bits/stdc++.h>
using namespace std;
int main(){
  int d; cin >> d;
  long n; cin >> n;
  int i = 0;
  if(n == 100) n =101;
    while(i < d){
      n *= 100;
      i++;
    }
  cout << n;
}
  