#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B,K;
  cin>>A>>B>>K;
  vector<int>nazo(110,0);
  int a=1;
 for(int i=min(A,B);i>=1;i--){
 	if(A%i==0 && B%i==0){
    	nazo.at(a)=i;
      a++;
    }
 }
  cout<<nazo.at(K)<<endl;
}