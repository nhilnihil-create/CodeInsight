#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define REP(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
long long maxv = 1e9;

int main()
{
    int n;
    cin>>n;
    int a;
    int ans;
    cin>>ans;
    REP(i,1,n-1){
        cin>>a;
        ans=__gcd(ans,a);
    }
    cout<<ans;
    return 0;
}