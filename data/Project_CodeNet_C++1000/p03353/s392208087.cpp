#include<bits/stdc++.h>
using namespace std;
string s,t;
set<string> st;
set<string>::iterator ip;
int l,k;
int main()
{
    cin>>s;
    l=s.length();
    cin>>k;
    for(int i=0;i<=l;i++)
    {
        for(int le=1;le<=k&&i+le-1<l;le++)
        {
            t=s.substr(i,le);
            st.insert(t);
        }
        
    }
    ip=st.begin();
    for(int i=1;i<k;i++) ip++;
    cout<<*ip;
}