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
    int a,b,c,G;
    cin>>a>>b>>c>>G;
    vector<ll>x,y,z;
    for(int i=1; i<=a; i++)
    {
        ll it;
        cin>>it;
        x.push_back(it);
    }
    for(int i=1; i<=b; i++)
    {
        ll it;
        cin>>it;
        y.push_back(it);
    }
    for(int i=1; i<=c; i++)
    {
        ll it;
        cin>>it;
        z.push_back(it);
    }
    vector<ll>ans;
    sort(all(x));
    sort(all(y));
    sort(all(z));
    reverse(all(x));
    reverse(all(y));
    reverse(all(z));
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            for(int k=0; k<c; k++)
            {

                if(((i+1)*(j+1)*(k+1))>G)
                    break;
                ans.push_back(x[i]+y[j]+z[k]);
            }
        }
    }
    sort(all(ans));
    int sz=ans.size();
    for(int i=sz-1,j=G; j>0; i--,j--)
    {
        cout<<ans[i]<<endl;
    }







    return 0;
}
