#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  if (N/100-N/1000*10 != N/10-N/100*10){
       cout << "No" << endl;}
  else if ((N/1000 == N/100-N/1000*10) || (N/10-N/100*10 == N-N/10*10)){
     cout << "Yes" << endl;}
  else{
    cout << "No" << endl;}
  
}
