#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=2e5+9;
int main()
{
    FASTINOUT;
    int x,t,a,b;
    cin>>x>>t>>a>>b;
    cout<<(x-a)*(t-b);
    return 0;
}
