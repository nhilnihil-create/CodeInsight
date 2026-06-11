#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
using vll=vector<ll>;
using vi=vector<int>;
int main(){
  int a,b,c=0,i;
  cin>>a>>b;
  for(i=0;i<2;i++){
    if(a>=b){c+=a;a--;}
    else{c+=b;b--;}
  }
  cout<<c<<endl;
}