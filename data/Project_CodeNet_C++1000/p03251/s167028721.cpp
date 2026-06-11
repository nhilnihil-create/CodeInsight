#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define all(v) v.begin() , v.end()
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main()
{   fastio;

    int n , m , X , Y;
    cin>>n>>m>>X>>Y;
    int x[n];
    int y[m];
    for(int i=0; i<n; i++)
        cin>>x[i];
    for(int j=0; j<m; j++)
        cin>>y[j];

    int fl=0;
    sort(x , x+n);
    sort(y , y+m);

    if(y[0]-x[n-1]>0)
    {
        for(int i=x[n-1]+1; i <= y[0]; i++)
        {
            if(i <= Y && i>X) {
                cout<<"No War\n";
                return 0;
            }
        }
        cout<<"War\n";
        return 0;
    }
    cout<<"War\n";
    return 0;


}