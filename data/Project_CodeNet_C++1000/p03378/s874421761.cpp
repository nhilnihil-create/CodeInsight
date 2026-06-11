#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(m);
    rep(i,m)cin>>a[i];
    int zero=0;
    int ngoal=0;
    rep(i,m)
    {
        if(a[i]<x)
        {
            zero+=1;
        }
        else if(a[i]>x)
        {
            ngoal+=1;
        }
    }
    cout<<min(zero,ngoal);
}
