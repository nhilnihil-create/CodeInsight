#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    string s;
    cin>>n>>s;
    ll mx=LLONG_MIN;
    for(int i=1;i<n;i++)
    {
        string a=s.substr(0,i);
        string b=s.substr(i,n-i);
        set<char>st;
        for(int i=0;i<a.size();i++)
        {
            char x=a[i];
            for(int j=0;j<b.size();j++)
            {
                if(x==b[j])
                {
                    st.insert(x);
                }
            }
        }
        mx=max(mx,(ll)st.size());
        st.clear();
    }
    cout<<mx<<endl;
}
