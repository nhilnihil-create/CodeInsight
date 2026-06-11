#include <bits/stdc++.h>
using namespace std;
int main(){
 double a;
 string b;
 double total = 0;
 int N;
 cin >> N;
  for(int i=0;i<N;i++){
    cin >> a >> b;
    if(b == "JPY") total+=a;
    else total+=380000*a;
  }
  cout << total << endl;
}    