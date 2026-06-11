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
    ll n,i,j,cc=0;
    ll ara[5];
    for(i=0;i<5;i++)cin>>ara[i];
    pair<ll,ll>v[10];
    for(i=0;i<5;i++){
        ll x=ara[i]%10;
        if(x != 0)
        v[i]=make_pair(10-x,ara[i]);
        else{
            v[i]=make_pair(0,ara[i]);
        }
    }
    sort(v,v+5);
    for(i=0;i<5;i++){
       // cout<<v[i].first<<spc<<v[i].second<<endl;
        if(i+1 != 5){
            cc+=v[i].first;
            cc+=v[i].second;
        }
        else{
            cc+=v[i].second;
        }
    }
    cout<<cc<<endl;
return 0;
}
