#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long A,B,C,K;
  cin>>A>>B>>C>>K;
  for(int X=0;X<K;X++){
    long long AA=B+C;
    long long BB=A+C;
    long long CC=A+B;
    A=AA;
    B=BB;
    C=CC;
  }
  if(A-B<1000000000000000000){
    cout<<A-B<<endl;
  }
  else{
    cout<<"Unfair"<<endl;
  }
}