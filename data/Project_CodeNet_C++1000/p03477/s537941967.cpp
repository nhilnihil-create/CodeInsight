#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    /*string s;
    cin>>s;
    if((s[0]==s[1]&&s[1]==s[2])||(s[1]==s[2]&&s[2]==s[3]))
      cout<<"Yes";
    else
      cout<<"No";*/
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<((a+b)>(c+d)?"Left":((a+b)==(c+d)?"Balanced":"Right"));
    nl;
    return 0;
}
