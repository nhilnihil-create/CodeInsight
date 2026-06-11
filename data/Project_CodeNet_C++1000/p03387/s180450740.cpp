#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin>>A>>B>>C;
  if((A%2+B%2+C%2)%3==0)
    cout<<(max({A,B,C})*3-(A+B+C))/2<<endl;
  else if(A%2+B%2+C%2==1)
    cout<<((max({A,B,C})/2*2+1)*3-(A+B+C))/2<<endl;
  else if(A%2+B%2+C%2==2)
    cout<<(((max({A,B,C})+1)/2*2)*3-(A+B+C))/2<<endl;
}