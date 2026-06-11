#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=2e5+100;
int main()
{
    FASTINOUT;
    ll x,y;
    cin>>x>>y;
    if (x>y)
        swap(x,y);
    if (x==1 &&y==1)
        cout<<1<<endl;
    else if (x==1)
        cout<<y-2<<endl;
    else
        cout<<(x-2)*(y-2)<<endl;
    return 0;
}
