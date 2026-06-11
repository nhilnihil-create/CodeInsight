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
#define N ((int)(2e5 + 2))
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
    int n;
    scanf("%d",&n);
    if(n==3){
        printf("2 5 63\n");
        return 0;
    }
    int x = min(15000,n-2);
    n -= x;
    if(n%2==1){
        n++;
        x--;
    }
    if(x%3==1){
        printf("%d ",2*(x+2));
        x--;
    }
    for(int i = 1; i<=x; i++) printf("%d ",i*2);
    for(int i = 1; i<=n; i++) printf("%d ",3*(2*i-1));
    return 0;
}
