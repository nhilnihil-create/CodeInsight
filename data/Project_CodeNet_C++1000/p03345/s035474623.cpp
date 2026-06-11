#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
int main(){
  long long A,B,C,K,S;
  cin>>A>>B>>C>>K;
  if(K%2==0) S=A-B;
  else S=B-A;
  cout<<S<<endl;
}
