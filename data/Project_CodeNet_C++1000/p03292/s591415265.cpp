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
   for(int i=0;i<3;i++)
    cin>>arr[i];
   int mx=INT_MAX;
   mx=min(mx,abs(arr[0]-arr[1])+abs(arr[1]-arr[2]));
   mx=min(mx,abs(arr[0]-arr[2])+abs(arr[1]-arr[2]));
   mx=min(mx,abs(arr[0]-arr[1])+abs(arr[0]-arr[2]));
   cout<<mx<<endl;


    return 0;
}
