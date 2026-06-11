#include<bits/stdc++.h>
using namespace std;

void Max(int &a,int x){
  a=max(a,x);
}

string s;
int mem[305][305][305];
int rec(int l,int r,int k){

  if( mem[l][r][k] != -1 )return mem[l][r][k];
  
  if(l==r)return 1;
  if(l>r)return 0;
  
  int res=0;
  
  if(s[l]==s[r]){
    Max(res,rec(l+1,r-1,k)+2);
  }

  Max(res,rec(l+1,r,k));
  Max(res,rec(l,r-1,k));
  if(k>0){
    Max(res,rec(l+1,r-1,k-1)+2);
  }

  
  return mem[l][r][k]=res;
}

int main(){
  memset( mem, -1, sizeof(mem) );
  cin>>s;
  int k;
  cin>>k;

  cout<< rec(0, s.size()-1 , k) <<endl;
  return 0;
}
