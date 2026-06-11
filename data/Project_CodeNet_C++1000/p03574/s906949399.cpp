#include<bits/stdc++.h>
using namespace std;
#define REP(i,N) for(int (i)=0;(i)<(N);(i)++)
#define REPR(i,N) for(int (i)=(N);i>=0;i--)
#define FOR (i,m,n) for(int (i)=m;(i)<(n);(i)++)

int main(){
  int H, W,sum;
  string s0,s1,s2,temp;
  cin >> H >> W;

  cin >>s1 >>s2;

  
  REP(i,H){
    if(i>0){
      s0=s1;
      s1=s2;
      cin >>s2;
	}
    
    REP(j,W){
      sum=0;
      
      if(i>0 && j>0)if(s0.at(j-1)=='#')sum++;
      if(i>0)if(s0.at(j)=='#')sum++;
      if(i>0 && j<W-1 && W>1)if(s0.at(j+1)=='#')sum++;

      if(j>0)if(s1.at(j-1)=='#')sum++;
      if(s1.at(j)=='#')sum++;
      if(j<W-1 && W>1)if(s1.at(j+1)=='#')sum++;

      if(i<H-1 && j>0)if(s2.at(j-1)=='#')sum++;
      if(i<H-1)if(s2.at(j)=='#')sum++;
      if(i<H-1 && j<W-1 && W>1)if(s2.at(j+1)=='#')sum++;
      
      if(s1.at(j)=='#'){
	cout << '#';
	continue;
      }
      cout <<sum;
    }
    
    cout <<endl;
  }
}