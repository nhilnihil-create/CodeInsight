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
     ll a,b,k;
     cin>>a>>b>>k;
     k=min(k,(b-a)+1);
     set<int>s;
     for(int i=a;i<=a+k-1;i++)
        s.insert(i);
     for(int i=b;i>=b-k+1;i--)
        s.insert(i);
     for(auto x:s)
        cout<<x<<endl;

    return 0;
}
