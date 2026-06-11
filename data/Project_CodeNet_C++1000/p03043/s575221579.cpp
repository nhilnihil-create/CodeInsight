#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
double half[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    half[1]=0.5;
    for(int i=2; i<MAX-10; i++)
        half[i]=half[i-1]*0.5;
    // for(int i=1;i<=10;i++)
    //  cout<<setprecision(10)<<fixed<<half[i]<<endl;
    int n,k;
    cin>>n>>k;
    double sum=0;
    for(ll i=1; i<=n; i++)
    {
        ll cur=i,cnt=0;
        double low=(1.0/((double)n));
        if(i>=k)
        {
            sum+=low;
            continue;
        }
        while(cur<k)
        {
            cur*=2ll;
            cnt++;
        }

        double x=half[cnt];

        sum+=(half[cnt]*low);
    }

    cout<<setprecision(10)<<fixed<<sum<<endl;


    return 0;
}
