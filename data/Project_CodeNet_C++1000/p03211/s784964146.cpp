#include <bits/stdc++.h>
using namespace std;
int main()
{   int_fast64_t s;
cin>>s;
int c=1000;
while(s>=100){
  int a=s%1000;
  int b=abs(a-753);
  c=min(c,b);
  s/=10;
}
cout<<c<<endl;
}