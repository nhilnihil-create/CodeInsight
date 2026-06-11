#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
  cin>>a;
  if(a==000) b=0;
  else if(a==100||a==10||a==001) b=1;
  else if(a==110||a==101||a==11) b=2;
  else b=3;
  printf("%d",b);
}