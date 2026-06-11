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
    int arr[5];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    if((arr[1]-arr[0])%2==0)
    {
        int dif=(arr[1]-arr[0])/2;
        dif+=arr[2]-arr[1];
        cout<<dif<<endl;
    }
    else if((arr[2]-arr[0])%2==0)
    {
        int dif=(arr[2]-arr[0])/2;
        while(arr[1]<arr[2])
            arr[1]+=2,dif++;
        cout<<dif+1<<endl;
    }
    else
    {
        int dif=(arr[2]-arr[1])/2;
         while(arr[0]<arr[2])
            arr[0]+=2,dif++;
        cout<<dif+1<<endl;

    }


    return 0;
}
