#include <bits/stdc++.h>
using namespace std;
#define   nl   <<'\n'
#define   pi   acos(-1.0);
#define   ll   long long
#define   pb   push_back
#define   eb   emplace_back
#define   tc   int t; cin>>t; while(t--)
#define   fio  ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio;
    int a,b,c=0;
    cin>>a>>b;
    for(int i=a; i<=b; i++)
    {
        string s=to_string(i);
        if(s[0]==s[4] && s[1]==s[3]) c++;
    }
    cout<<c;
}  