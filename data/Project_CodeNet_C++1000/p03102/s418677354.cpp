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
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int cnt=0;
    int n,m,c;
    cin>>n>>m>>c;
    for(int i=0; i<m; i++)
        cin>>arr[i];
    while(n--)
    {
        ll sum=c;
        for(int i=0; i<m; i++)
        {
            int a;
            cin>>a;
            a*=arr[i];
            sum+=a;
        }
        if(sum>0)
            cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
