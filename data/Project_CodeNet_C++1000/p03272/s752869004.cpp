#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define pi              acos(-1)
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MAX             100005
#define MOD             1000000007

typedef long long ll;


int main()
{
    FastRead

    ll n,a,b;

    cin>>a>>b;

    cout<<(a-b)+1;
}
