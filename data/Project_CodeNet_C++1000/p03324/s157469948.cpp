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
#define F first
#define S second
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int d,n,no=0;
    cin>>d>>n;
    for(int i=1; i<=1e8; i++)
    {
        int cnt=0;
        int temp=i;
        while(temp%100==0)
        {
            cnt++;
            temp/=100;
        }
        if(cnt==d)
            no++;
        if(no==n)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
