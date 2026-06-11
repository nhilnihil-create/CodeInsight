#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

int main()
{
	
string s;
int c=0,an=0;
cin>>s;
for(int i=0;i<(int)s.size();i++)
if(s[i]=='A'||s[i]=='T'||s[i]=='C'||s[i]=='G'){c++;an=max(an,c);}
else{an=max(an,c);c=0;}
cout<<an<<endl;

}

