#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;cin>>s;
  int a1=s.find("KIH");
  int a2=s.find("B");
  int a3=s.find("R");
  auto ch=string::npos;
  int n=s.size();
  if(a1==ch||a2==ch||a3==ch)cout<<"NO"<<endl;
  else
  {
    bool ok=true;
    if(a1>=2||a1==1&&s.at(0)!='A')ok=false;
    if(a2-a1!=3&&a2-a1!=4)ok=false;
    if(a2-a1==4&&s.at(a2-1)!='A')ok=false;
    if(a3-a2!=1&&a3-a2!=2)ok=false;
    if(a3-a2==2&&s.at(a3-1)!='A')ok=false;
    if(a3<n-2||a3==n-2&&s.at(n-1)!='A')ok=false;
    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
