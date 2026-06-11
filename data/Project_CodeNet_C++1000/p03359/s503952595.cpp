#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=5e5+10;
int main()
{
    FASTINOUT;
    int x,y;
    cin>>x>>y;
    cout<<x+(y>=x?0:-1)<<endl;
    return 0;
}
