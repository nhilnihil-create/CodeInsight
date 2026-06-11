#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((ll)(2e9))
#define pi (acos(-1))
#define M ((ll)(998244353))
#define NN ((ll)(1e4+2))
#define N ((ll)(1e5 + 5))
#define eps 0
#define log 20


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
/// typedef tree < pair < ll,ll >,  null_type,  less < pair < ll,ll > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).

ll gcd(ll a , ll b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll a , b ,  c, d;
        cin>>a>>b>>c>>d;
        if(a<b || d<b){
            cout<<"No\n";
        }
        else{
            a %= b;
            d %= b;
            d = gcd(d,b);
            ll g = b-1-a;
            ll k = g/d;
            a += k*d;
            if(a>c){
                cout<<"No\n";
            }
            else cout<<"Yes\n";
        }
    }
    return 0;
}
