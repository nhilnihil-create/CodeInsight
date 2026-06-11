#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int p;cin>>p;
  int arr[p];
  int A,B; cin>>A>>B;
  int u=0,d=0,t=0;
  
  for(int i=0; i<p; i++){
    cin>>arr[i];
  }
  
  for(int i=0; i<p; i++){
    if(arr[i]<=A)u++;
    else if(arr[i]<=B)d++;
    else t++;
  }
  int rta = min({u,d,t});
  cout<<rta<<'\n';
}