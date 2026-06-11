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
int check(int a)
{
    int b=0;
    while(a>0)
    {
        b*=10;
        b+=(a%10);
        a/=10;
    }
    return b;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int a,b,c=0;
    cin>>a>>b;
    for(int i=a; i<=b; i++)
    {
        if(i==check(i))
            c++;
    }
    cout<<c<<endl;

    return 0;
}
