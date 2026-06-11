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
int arr[500];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    while(1)
    {
        int res=0,f=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i])
            {
                arr[i]--;
                res=1;
            }
            else if(res)
            {
                f=1;
                res=0;
                cnt++;
            }
        }
        if(res)
            cnt++,f=1;
        if(!f)
            break;
    }
    cout<<cnt<<endl;

    return 0;
}
