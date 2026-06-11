#include<iostream>

using namespace std;

int main(void)
{
  int a,b,x; cin>>a>>b>>x;
  int sum=0;
  
  for(int i=0;i<=b;i++){
    if((a+i)==x){puts("YES"); return 0;}
  }
  
  puts("NO");
  return 0;
}