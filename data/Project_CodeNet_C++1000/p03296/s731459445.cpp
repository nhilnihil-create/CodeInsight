#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int j=0,k=100000,l=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a==k)
      l++;
    else{
      j+=l/2;
      l=1;
      k=a;
    }
  }
  cout<<j+l/2<<endl;
}