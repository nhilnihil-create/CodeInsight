#include <iostream>
#include <bits/stdc++.h>
#define mod 998244353
#define point complex<double>
#define pi acos(-1)
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Fastio();
    int ttt=1; //cin>>ttt;
    while(ttt--){
        ll n, arr[105][11], p[105][12];
        cin>>n;
        for(int i=0; i<n; i++){
            for(int y=0; y<10; y++){
                cin>>arr[i][y];
            }
        }
        for(int i=0; i<n; i++)
            for(int y=0; y<=10; y++){cin>>p[i][y];}
        ll res=-1e18;
        for(int i=1; i<=(1<<10)-1; i++){
            ll ans=0;
            for(int y=0; y<n; y++){
                int c=0;
                for(int j=0; j<10; j++){
                    if(!arr[y][j] || (i>>j)%2==0)continue;
                    c++;
                }
                ans+=p[y][c];
            }
            res=max(res, ans);
        }
        cout<<res<<'\n';
    }

    return 0;
}
