#include<iostream>
#include <stdio.h>
#include<string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <queue> 
#include <map>
#include <set>
#define MOD 1000000007
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
using namespace std;
 
int main(){
 
  int m;
  cin >> m;
  
  int N[55];
  
  int p = 0,n = 0,pmax = 0,nmax = 0,pindex,nindex;
  REP(i,m){
    cin >> N[i];
    if(N[i] > 0){
      p = 1; 
      if(N[i]>pmax){
        pmax = N[i];
        pindex = i+1;
      }
    }
    else	    {
      n = 1;
       if(N[i] < nmax){
        nmax = N[i];
        nindex = i+1;
      }
    }
  }
  
  int x[100],y[100],count = 0;
  
  if(p == 1 && n == 1){
    if(pmax >= nmax*-1){
      REP(i,m){
      N[i] += pmax;
      x[count] = pindex;
      y[count] = i+1;
      count++;
      }
      n = 0;
    }
    
    else               {
      REP(i,m){
      N[i] += nmax;
      x[count] = nindex;
      y[count] = i+1;
      count++;
        }
        p = 0;
    }
  }
  
  if(p == 1){
  REP(i,m-1){
        x[count] = i+1;
        y[count] = i+2;
        count++;        
      }
  }
   else{
   for(int i = m-1; i > 0; i--){
       x[count] = i+1; 
       y[count] = i;
       count++;
      }
   }
      
  
  cout << count << endl;
  
  REP(i,count) cout << x[i] << " " << y[i] << endl;
    
 
 return 0;
}