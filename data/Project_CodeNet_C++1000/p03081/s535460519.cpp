#include<bits/stdc++.h>
using namespace std;
char x[200010],y[200010];
long n,q,c=-1,d;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q>>s;
    d=n;
    for(int i=0; i<q; i++)
        cin>>x[i]>>y[i];
    for(int i=q-1; i>=0; i--)
    {
        if(x[i]==s[c+1]&&y[i]=='L')
            c++;
        if(x[i]==s[d-1]&&y[i]=='R')
            d--;
        if(x[i]==s[c]&&y[i]=='R')
            c--;
        if(x[i]==s[d]&&y[i]=='L')
            d++;
    }
    cout<<max(0,(int)(d-c-1))<<endl;
    return 0;
}
