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
ll arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
     arr[0]=2;
    arr[1]=1;
    for(int i=2;i<=86;i++)
        arr[i]=arr[i-1]+arr[i-2];
    int n;
    cin>>n;
    cout<<arr[n]<<endl;
    return 0;
}
