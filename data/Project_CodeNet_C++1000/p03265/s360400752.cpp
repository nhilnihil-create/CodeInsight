#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h,n,m;
int main()
{
  cin>>a>>b>>c>>d;
  n=abs(a-c);m=abs(b-d);
  if(a<c){
    if(b>d)cout<<c+m<<" "<<d+n<<" "<<a+m<<" "<<b+n;
    else cout<<c-m<<" "<<d+n<<" "<<a-m<<" "<<b+n;
  }else{
    if(b>d)cout<<c+m<<" "<<d-n<<" "<<a+m<<" "<<b-n;
    else cout<<c-m<<" "<<d-n<<" "<<a-m<<" "<<b-n;
  }
}