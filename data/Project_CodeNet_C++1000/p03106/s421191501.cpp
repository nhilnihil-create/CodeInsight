#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  int K=0;
  if(a>b){
    int t=a;
    a=b;
    b=t;
  }
  int A=a,s;
  while(1){
    if(a%A==0 && b%A==0){
      s=A;
      K+=1;
    }
    if(K==k){
      cout<<s<<endl;
      break;
    }
    A--;
  }
}
