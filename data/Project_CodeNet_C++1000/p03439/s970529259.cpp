#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(ll i=(n);i<(k);i++)
ll n;
ll who(ll t){
  cout<<t<<endl;
  string S;cin>>S;
  if(S=="Male"){
    return 0;
  }
  if(S=="Female"){
    return 1;
  }
  if(S=="Vacant"){
    return 2;
  }  
}
void Main(){   
    cin>>n;
    vector<int> chair(n);
    chair.at(0)=who(0);
    if(chair.at(0)==2){
      return;
    }
    chair.at(n-1)=who(n-1);
    if(chair.at(n-1)==2){
      return;
    }
    ll left=0,right=n-1;
    ll center;
    For(i,2,20){
      center=(left+right)/2;
      chair.at(center)=who(center);
      if(chair.at(center)==2){
        return;
      }
      if((center+chair.at(center))%2==(left+chair.at(left))%2){
        left=center;
      }
      else{
        right=center;
      }      
    }
}
int main(){
    Main();
    return 0;
}