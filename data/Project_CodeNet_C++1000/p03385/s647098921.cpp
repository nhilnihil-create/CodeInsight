#include <bits/stdc++.h>
using namespace std;
long long A[50];
int main()
{
long long a,b,i,c=1,d=0,n,m,t,k;
string s;
cin>>s;
sort(s.begin(),s.end());
if(s[0]=='a'&&s[1]=='b'&& s[2]=='c') std::cout << "Yes" << '\n';
else std::cout << "No" << '\n';
return 0;
}
