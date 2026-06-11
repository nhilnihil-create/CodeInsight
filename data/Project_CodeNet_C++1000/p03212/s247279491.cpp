#include <bits/stdc++.h>
using namespace std;

int64_t n;

void f(int64_t x,int64_t &res,int bit){
  if(x>n)return;
  if(bit==0b111)res++;
  
  f(x*10+5,res,bit|0b001);
  f(x*10+7,res,bit|0b010);
  f(x*10+3,res,bit|0b100);
}

int main(){
  cin >>n;
  int64_t res=0;
  f(0,res,0);
  cout <<res<<endl;
}