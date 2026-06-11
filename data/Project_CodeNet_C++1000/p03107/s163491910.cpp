#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
string s;
cin>>s;
stack<char> st;
st.push(s[0]);
for(int i=1;i<s.length();i++)
{
if(st.size()==0)
{
st.push(s[i]);
continue;
}
if(s[i]!=st.top())
{
st.pop();
}
else
{
st.push(s[i]);
}
}
cout<<s.length()-st.size()<<endl;
}