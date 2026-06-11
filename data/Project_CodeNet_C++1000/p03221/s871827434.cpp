/*                        ______
 _______   /\     |``\   |        |  /
    |     /  \    |__/   |____    |/
    |    / _ _\   |  \   |        |\
    |   /      \  |   \  |______  |  \

            Dept. of CSE
        Comilla  University

*/
#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Node struct node
#define spc " "
#define  E  2.71828182845904523536
#define pb push_back
#define pp pop_back
#define valid(nx,ny) nx>=0 && nx<n && ny>=0 && ny<m
#define ee endl
#define pii pair<int,int>
#define infinity 10000000000000000
#define mod 1000000007
int fx[]={0,0,+1,-1};
int fy[]={+1,-1,0,0};

using namespace std;
///check n=1;
///check corner case;
const int maX=1e5+1;
vector<ll>Graph[maX],cost[maX];
ll visit[maX];
ll x[10];
ll y[10];

int main()
{
    ll n,m,i,j,cc=0;
    cin>>n>>m;
    map<ll,ll>check;
    map<ll,ll>ara;
    map<ll,ll>fuck;
    ll p[m],y[m],dj[m];
    for(i=0;i<m;i++){
        cin>>p[i]>>y[i];
        dj[i]=y[i];
        check[y[i]]=p[i];
    }
    sort(y,y+m);
    for(i=0;i<m;i++){
        fuck[check[y[i]]]++;
        ara[y[i]]=fuck[check[y[i]]];
    }
    for(i=0;i<m;i++){
        ll x=ara[dj[i]];
        ll y=p[i];
        printf("%06ld",y);
        printf("%06ld\n",x);
    }
return 0;
}
