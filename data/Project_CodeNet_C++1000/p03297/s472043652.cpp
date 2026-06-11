#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)(1e7))
#define pi (2*acos(0))
#define mp make_pair
#define M ((int)(1e9 + 7))
#define xx first
#define yy second
#define NN ((int)(5e5+2))
#define N ((int)(4e2 + 2))
#define pq priority_queue
///#define Q queue
#define eps 0
#define log 20
#define pb push_back
#define MOD 998244353


using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int lu;

typedef tree < int ,  null_type ,  less < int > ,  rb_tree_tag ,  tree_order_statistics_node_update > o_set;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(a<b || d<b) printf("No\n");
        else{
            if(c+1>=b){
                printf("Yes\n");
            }
            else{
                ll s = a - b*(a/b);
                ll l = c+1-s, r = b-1-s, x = d%b;
                if(x>0) x = __gcd(x,b);
                if(l<=0 || (x>0 && ((l/x)*x==l || ((1 + l/x)*x<=r && (1 + l/x)*x>=l)))) printf("No\n");
                else printf("Yes\n");
            }
        }
    }
    return 0;
}
