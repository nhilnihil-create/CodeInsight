#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m) for(int i=(int)(n);i<(int)(m);i++)

//library----------------------------------------------


int main(){
  int a,b;cin>>a>>b;
  if(b%a==0){
    printf("%d\n",a+b);
  }else{
    printf("%d\n",b-a);
  }
  
  return 0;
}