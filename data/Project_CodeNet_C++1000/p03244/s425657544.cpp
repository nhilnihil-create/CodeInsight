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
    ll n,i,j,cc=0,v=0;
    cin>>n;
    ll ara[n];
    for(i=0;i<n;i++)cin>>ara[i];
    map<ll,ll>check;
    ll mx=0;
    for(i=0;i<n;i+=2){
        check[ara[i]]++;
        if(mx<check[ara[i]]){
            mx=check[ara[i]];
            v=ara[i];
        }
    }
    ll x=(n/2)-mx;
    //cout<<v<<endl;
    mx=0;
    check.clear();
    for(i=1;i<n;i+=2){
        check[ara[i]]++;
        if(mx<check[ara[i]] && ara[i] != v){
            mx=check[ara[i]];
        }
    }
    x+=(n/2)-mx;//cout<<mx<<endl;
    mx=0;
    v=0;
    check.clear();
    for(i=1;i<n;i+=2){
        check[ara[i]]++;
        if(mx<check[ara[i]]){
            mx=check[ara[i]];
            v=ara[i];
        }
    }
     ll y=(n/2)-mx;
    mx=0;
    check.clear();
        for(i=0;i<n;i+=2){
        check[ara[i]]++;
        if(mx<check[ara[i]] && v != ara[i]){
            mx=check[ara[i]];
        }
    }
    y+=(n/2)-mx;
    cout<<min(x,y)<<endl;
return 0;
}
