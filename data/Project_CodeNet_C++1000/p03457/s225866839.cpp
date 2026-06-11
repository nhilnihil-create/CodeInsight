#include<bits/stdc++.h>
using namespace std;
typedef long l;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
long a,b,c;
int main()
{
    l n,t,x,y,k;
    a = b = c = 0;
    cin>>n;
    FOR(i,0,n)
    {
        cin>>t>>x>>y;
        k = abs(a - x) + abs(b - y);

        if(c + k > t ) { cout<<"No"<<'\n'; return 0;}
        if(k%2 != (t - c) % 2){ cout<<"No"<<'\n'; return 0;}

        a = x;
        b = y;
        c = t;

    }
    cout << "Yes"<<'\n';
    return 0;
}
