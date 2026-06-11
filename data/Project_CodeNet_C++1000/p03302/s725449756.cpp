#include<bits/stdc++.h>
#include <assert.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define repn(a,b,c) for(int a=b;a>=c;a--)
#define ll long long 
#define sum(a,b) a=a+b
#define mem(a, b) memset(a, (b), sizeof(a))
#define ctz(x) __builtin_ctz(x)
#define clz(x) __builtin_clz(x)
#define popcount(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)

//=======binarysearch===========
int bs(vector<int>&a,int que){
 auto it=lower_bound(a.begin(),a.end(),que);
 if(*it==que){
    return it-a.begin();
 }
 return -1;
}
//========binarysearch=========


bool isprime(int x)
{
  if ( x == 2 ) return true;
  if ( x  < 2 ) return false;
  for ( int i = 2; i * i <= x; i++ )
    if ( x % i == 0 ) return false;


  if(x==0) return false;
  return true;
}


int main(){
  
  int a,b;

  cin>>a>>b;

  if(a*b==15){
    cout<<"*";
  }else if(a+b == 15){

    cout<<"+";
  }else if(a*b!= 15 && a+b!=15){
    cout<<"x";
  }



}