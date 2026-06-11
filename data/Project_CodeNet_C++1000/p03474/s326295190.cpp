#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int  a,b;
    string s;
    cin>>a>>b;
    cin>>s;
    if(s[a]!='-')
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0; i<a; i++)
    {
        if(!(s[i]>='0' && s[i]<='9'))
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=a+1; i<a+1+b; i++)
    {
        if(!(s[i]>='0' && s[i]<='9'))
        {
            cout<<"No"<<endl;
            return 0;
        }
    }




    cout<<"Yes"<<endl;

    return 0;
}
