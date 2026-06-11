#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=2e5+9;
int main()
{
    FASTINOUT;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<min(a,b)+min(c,d)<<endl;
    return 0;
}
