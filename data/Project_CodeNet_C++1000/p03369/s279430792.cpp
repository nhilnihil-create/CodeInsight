#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,d=0;
string s;
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]=='o')
        d++;
}
cout<<700+(100*d);
       return 0;
}