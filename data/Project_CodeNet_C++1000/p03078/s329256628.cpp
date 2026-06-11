#include <bits/stdc++.h>

#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
typedef long double ld;
using namespace std;
#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
const int N=1e3+5, mxN=(1<<22);
int mod=1e9+7;
int n;
ll a[N],b[N],c[N];
priority_queue<ll>qq,q;


int main()
{
    FIO
int x,y,z,k;

cin>>x>>y>>z>>k;
for(int i=0;i<x;i++)
    cin>>a[i];
sort(a,a+x,greater<int>());

for(int i=0;i<y;i++)
    cin>>b[i];


for(int i=0;i<z;i++)
    cin>>c[i];



    for(int j=0;j<y;j++)
    {

        for(int ind=0;ind<z;ind++)
        {
           q.push(b[j]+c[ind]);

        }
    }
    for(int z=0;z<3000&&q.size();z++)
    {

        for(int i=0;i<x;i++)
        {

            qq.push(q.top()+a[i]);

        }
q.pop();

    }

while(k--)
{
    cout<<qq.top();
    qq.pop();
    if(k)
        cout<<endl;

}


    return 0;

}




