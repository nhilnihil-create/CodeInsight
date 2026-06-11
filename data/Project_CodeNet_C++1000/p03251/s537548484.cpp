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
    ll n,i,m,x,j,y;
    cin>>n>>m>>x>>y;
    ll ara[n];
    ll bra[m];
    for(i=0;i<n;i++)cin>>ara[i];
    for(j=0;j<m;j++)cin>>bra[j];
    sort(ara,ara+n);
    sort(bra,bra+m);
    ll z=ara[n-1]+1;
    if(z> x && z<=y && z<=bra[0])cout<<"No War"<<endl;
    else cout<<"War"<<endl;
return 0;
}
