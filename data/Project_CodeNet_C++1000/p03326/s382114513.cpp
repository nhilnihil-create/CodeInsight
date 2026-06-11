#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

int n,m;

struct node
{
    ll x,y,z;

}a[2000];

bool cmp1(node x,node y)
{
     return x.x+x.y+x.z>y.x+y.y+y.z;
}

bool cmp2(node x,node y)
{
     return x.y+x.z-x.x>+y.y+y.z-y.x;
}

bool cmp3(node x,node y)
{
     return x.x-x.y+x.z>y.x-y.y+y.z;
}

bool cmp4(node x,node y)
{
     return x.x+x.y-x.z>y.x+y.y-y.z;
}

bool cmp5(node x,node y)
{
     return -x.x-x.y+x.z>-y.x-y.y+y.z;
}

bool cmp6(node x,node y)
{
     return -x.x+x.y-x.z>-y.x+y.y-y.z;
}

bool cmp7(node x,node y)
{
     return x.x-x.y-x.z>y.x-y.y-y.z;
}

bool cmp8(node x,node y)
{
     return -x.x-x.y-x.z>-y.x-y.y-y.z;
}
ll ans=0;

int dv[8][3]={{1,1,1},{-1,1,1},{1,-1,1},{1,1,-1},{-1,-1,1},{-1,1,-1},{1,-1,-1},{-1,-1,-1}};
void check(int q,int w,int e)
{
   ll sum=0;
   for(int i=1;i<=m;i++){
    sum+=q*a[i].x+w*a[i].y+e*a[i].z;
    }

    ans=max(ans,abs(sum));
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    int t=0;
    sort(a+1,a+n+1,cmp1);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;
    sort(a+1,a+n+1,cmp2);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;
    sort(a+1,a+n+1,cmp3);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;
    sort(a+1,a+n+1,cmp4);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;
    sort(a+1,a+n+1,cmp5);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;
    sort(a+1,a+n+1,cmp6);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;
    sort(a+1,a+n+1,cmp7);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;
    sort(a+1,a+n+1,cmp8);
    check(dv[t][0],dv[t][1],dv[t][2]);
    t++;

    cout<<ans<<endl;
    return 0;
}
