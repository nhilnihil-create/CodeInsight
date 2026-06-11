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
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    map<int,int>mp;
    int n;
    cin>>n;
    vector<int>v;
    mp[n]=1;
    int cnt=1;
    while(1)
    {
        cnt++;
        if(n%2==0)
            n/=2;
        else
            n=3*n+1;

        if(mp[n])
        {
            cout<<cnt<<endl;
            return 0;
        }
        mp[n]=1;

    }

    return 0;
}
