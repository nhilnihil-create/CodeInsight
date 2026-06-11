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
    ll i,j,cc=0,k,l,n;
    cin>>n>>k;
    string str;cin>>str;
    vector<ll>ara(n+1);
    ara[1]=0;
    ara[0]=0;
    for(i=1;i<n;i++){
        if(str[i-1]=='A' && str[i]=='C'){
            ara[i]+=ara[i-1]+1;
        }
        else {
            ara[i]=ara[i-1];
        }
    }
    while(k--){
        ll x,y;cin>>x>>y;
        x--,y--;
        if(x==0){
            cout<<ara[y]<<endl;
        }
        else{
            cout<<ara[y]-ara[x]<<endl;
        }
    }
return 0;
}
