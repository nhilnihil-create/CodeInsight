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
    string str;
    cin>>str;
    ll x,y,z,i,j;
    i=(str[0]-'0')*10;
    j=(str[1]-'0');
        x=i+j;
    y=(str[2]-'0')*10+(str[3]-'0');
     if(x<=12 && y<=12 && x != 0 && y != 0)cout<<"AMBIGUOUS"<<endl;
    else if(x<=12 && x >=1 )cout<<"MMYY"<<endl;
    else if(y>=1 && y<=12)cout<<"YYMM"<<endl;

    else cout<<"NA"<<endl;
return 0;
}
