#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    if(s<t)
      cout<<"Yes";
    else
      cout<<"No";
    nl;
    return 0;
}
