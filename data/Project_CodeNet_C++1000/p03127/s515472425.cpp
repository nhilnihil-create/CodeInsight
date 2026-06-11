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
    int n,mn=INT_MAX;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mn=min(mn,arr[i]);
    }
    while(1)
    {
        int new_mn=INT_MAX,sk=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==mn && !sk)
                sk=1;
            else
            {
                arr[i]%=mn;
                if(arr[i])
                {
                    new_mn=min(new_mn,arr[i]);
                }
            }
        }
        if(new_mn==INT_MAX)
            break;
        mn=new_mn;
    }
    cout<<mn<<endl;



    return 0;
}
