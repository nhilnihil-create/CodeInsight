#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long int a,b,c,k;
  cin>>a>>b>>c>>k;
  if(k%2==1){
    cout<<b-a;
  }else{
    cout<<a-b;
  }
}