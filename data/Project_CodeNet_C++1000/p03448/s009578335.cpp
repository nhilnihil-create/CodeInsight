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
    int a,b,c,x,cnt=0;
    cin>>a>>b>>c>>x;
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            for(int k=0; k<=c; k++)
            {
                if(((500*i)+(100*j)+(50*k))==x){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
