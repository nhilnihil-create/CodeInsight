#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;



int main()
{
    string s;
    cin>>s;
    string t;
    int n=s.length();
    for(auto v:s)
    {
        if(v!='x')
        {
            t+=v;
        }
    }
    if(t!=string(t.rbegin(),t.rend()))
    {
        cout<<-1<<endl;
    }
    else
    {
        int ans=0;
        int front=0;
        int back=n-1;
        while(back-front>0)
        {
            if(s[front]!=s[back])
            {
                ans++;
                s[front]=='x'?front++:back--;  
            }
            else
            {
                front++,back--;
            }
            
        }
        cout<<ans;
        
    }
    
}
