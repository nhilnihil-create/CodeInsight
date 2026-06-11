#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long X,Y;
  long long S=0;
  cin>>X>>Y;
  for(long long A=X;A<=Y;A*=2){
    S++;
  }
  cout<<S<<endl;
}
