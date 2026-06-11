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

    int n, cnt= 0, d= 0;

    cin>> n;

    if(n<105)
    {
        cout<< 0;
        nl;
        return 0;
    }

    for(int i=107; i<=n; i+=2)
    {
        d= 0;

        for( int j= 3; j* j<= i; j++)
        {
            if(i% j== 0)
            {
                if(i== j* j)
                    d++;
                else
                    d+= 2;
            }

            if(d> 6)
                break;
        }

        if(d== 6 )
            cnt++;
    }

    cout<< cnt + 1;
    nl;

    return 0;
}


