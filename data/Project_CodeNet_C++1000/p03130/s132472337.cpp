#include <bits/stdc++.h>
using namespace std;
  
int main(){
  int sum=0; 
  vector<int>A(4);
  for(int i=0;i<6;i++){
    int a; cin>>a;
    if(a==1) A[0]++;
    else if(a==2) A[1]++;
    else if(a==3) A[2]++;
    else A[3]++;
  }
  for(int i=0; i<4;i++){
    if(A[i]==2) sum++;
  }
  if(sum==2) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}