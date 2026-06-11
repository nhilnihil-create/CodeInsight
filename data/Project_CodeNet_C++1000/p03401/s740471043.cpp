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
    int x;
    cin>>x;
    int y[x+2];
    y[0]=0,y[x+1]=0;
    ll sum=0;
    for (int i=1;i<=x;i++){
        cin>>y[i];
        sum+=abs(y[i]-y[i-1]);
    }
    sum+=abs(y[x+1]-y[x]);
    for (int i=1;i<=x;i++){
        cout<<sum+abs(y[i+1]-y[i-1])-abs(y[i+1]-y[i])-abs(y[i]-y[i-1])<<endl;
    }
    return 0;
}
