#include <bits/stdc++.h>
using namespace std;
int main() {
string s;
cin>>s;
int counto=0,countz=0;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='1')
    counto++;
    else
    countz++;
}
if(countz>counto)
{
    cout<<2*counto;
}
else
cout<<2*countz;


}
