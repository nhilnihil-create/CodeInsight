#include<bits/stdc++.h>
using namespace std;

int d[1000001];
int main()
{
string s;int an=753;
cin>>s;
for(int i=2;i<(int)s.size();i++){
an=min(an,abs(753-(s[i]+s[i-1]*10+s[i-2]*100-5328)));}
cout<<an<<endl;

}

