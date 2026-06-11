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
int c[1000],s[1000],f[1000];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        cin>>c[i]>>s[i]>>f[i];
    }
    for(int i=0; i<n-1; i++)
    {
        int sum=s[i];
        for(int j=i+1; j<n; j++)
        {
            sum+=c[j-1];
            if(j==n-1)
                break;
            if(s[j]>sum)
                sum+=s[j]-sum;
            else{
                int cur=s[j];
                while(cur<sum)
                    cur+=f[j];
                sum+=cur-sum;
            }
        }
        cout<<sum<<endl;
    }
    cout<<"0"<<endl;

    return 0;
}
