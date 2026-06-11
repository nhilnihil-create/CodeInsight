#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,A,B,C,D,E;
  cin>>N>>A>>B>>C>>D>>E;
  cout<<4+N/min(A,min(B,min(C,min(D,E))))+(N%min(A,min(B,min(C,min(D,E))))+min(A,min(B,min(C,min(D,E))))-1)/min(A,min(B,min(C,min(D,E))))<<endl;
}