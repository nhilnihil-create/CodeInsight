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
int recur(int x,int y,int a,int b)
{

    return (abs(x-a)+abs(b-y));
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int x=0,y=0,n,f=0,last_t=0;
    cin>>n;
    while(n--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        int req=recur(x,y,a,b);
            int cur_t=t-last_t;
        if(req>cur_t){
            f=1;

        }
        else{
            int rem=cur_t-req;
            if(rem%2)
                f=1;

        }
        x=a;
        y=b;
        last_t=t;

    }
    if(!f)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

    return 0;
}
