#include<bits/stdc++.h>
using namespace std;

string s;
set<char> st;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
        st.insert(s[i]);
    if(st.size()==3)
        cout<<"Yes";
    else
        cout<<"No";

}
