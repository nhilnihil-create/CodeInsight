#include<iostream>
using namespace std;
int main(void)
{
  int a,b,c,d; cin>>a>>b>>c>>d;
  int d1,d2,d3;
  d1=abs(b-a);
  d2=abs(c-b);
  d3=abs(c-a);
  if(d1<=d){
    if(d2<=d){
      puts("Yes"); return 0;
    }
  }
  if(d3<=d){puts("Yes"); return 0;}
  puts("No");
  return 0;
}
