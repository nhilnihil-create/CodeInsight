#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin>>A>>B;
  int C=0;
  for(;A<=B;A++){
    int t=A;
    int A1=t%10;
    t/=10;
    int A2=t%10;
    t/=10;
    int A3=t%10;
    t/=10;
    int A4=t%10;
    t/=10;
    int A5=t%10;
    if(A1==A5&&A2==A4){
      C++;
    }
  }
  cout<<C<<endl;
}
