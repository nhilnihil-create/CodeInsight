#include <bits/stdc++.h>
#define rep(i,n) for<int i=0; ++i>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c,d,e,k;
  int ans=0;
  cin >> a >> b >> c >> d >> e >> k;
  if((b-a)<=k) ans+=1;
  if((c-a)<=k) ans+=1;
  if((d-a)<=k) ans+=1;
  if((e-a)<=k) ans+=1;
  
  if((c-b)<=k) ans+=1;
  if((d-b)<=k) ans+=1;
  if((e-b)<=k) ans+=1;
  
  if((d-c)<=k) ans+=1;
  if((e-c)<=k) ans+=1;
  
  if((e-d)<=k) ans+=1;
  
  if(ans==10){
    cout << "Yay!" << endl; 
  }
  else{
    cout << ":(" << endl;
  }
  return 0;
}