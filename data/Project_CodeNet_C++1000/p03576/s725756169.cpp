#include <bits/stdc++.h>
     
using namespace std;

#define ll long long int

vector <pair<ll,ll>> p;
int n,k;
ll x,y;
vector <ll> vx,vy;
int psum[51][51];
int check[51][51];
map <ll,int> compx,compy;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll res = 9223372036854775807;

    cin >> n >> k;

    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        p.push_back(make_pair(x,y));
        vx.push_back(x);
        vy.push_back(y);
    }

    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());

    for(int i=0;i<n;i++)
    {
        compx[vx[i]] = i+1;
        compy[vy[i]] = i+1;
    }

    for(int i=0;i<n;i++)
    {
        check[compx[p[i].first]][compy[p[i].second]] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + check[i][j];
        }
    }

    for(int i1=0;i1<n;i1++)
    {
        for(int i2=i1+1;i2<n;i2++)
        {
            for(int j1=0;j1<n;j1++)
            {
                for(int j2=j1+1;j2<n;j2++)
                {
                    int rx = compx[vx[i2]];
                    int lx = compx[vx[i1]];
                    int ry = compy[vy[j2]];
                    int ly = compy[vy[j1]];
                    int val = psum[rx][ry] - psum[lx-1][ry] - psum[rx][ly-1] + psum[lx-1][ly-1];
                    if(val==k)
                    {
                        res = min(res,(vx[i2]-vx[i1])*(vy[j2]-vy[j1]));
                    }
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}
