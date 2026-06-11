#include <iostream>

using namespace std;

int main()
{string s,x,ww;
cin>>s>>x;
ww=s;
if(s==x){cout<<"Yes"<<endl;}
else{
int y=s.size(),c=0;
while(true){
    char q;
    q=  s[y-1];;
for(int i=y-1;i>=1;i--){
    s[i]=s[i-1];
}
  s[0]=q;
    if(s==x){c++;
    break;}
   // y--;
   if(s==ww){c=0;
   break;}
}
if(c!=0){cout<<"Yes"<<endl;}
else{cout<<"No"<<endl;}
}
    return 0;
}