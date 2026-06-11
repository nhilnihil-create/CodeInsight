#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

    int n, m;
    cin>> n;
    if(n== 0)
    {
        cout<<  "No\n";
        return 0;

    }
    if(n%4== 0 || n%7== 0)
    {
        cout<<  "Yes\n";
        return 0;
    }

    m= n/ 7;


    while (m> 0)
    {
        if((n- (m*7)) % 4== 0)
        {
            cout<<  "Yes\n";
            return 0;
        }
        m--;
    }
    cout<<  "No\n";

    return 0;
}


