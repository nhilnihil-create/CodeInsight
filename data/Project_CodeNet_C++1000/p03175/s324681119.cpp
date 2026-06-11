#include <iostream>
#include <vector>
#include <math.h>
#include <list>

using namespace std;
typedef long long int ll;
ll MOD = pow(10,9) + 7;

void print(vector<ll>& v)
{
    for (auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void helper(vector<list<ll>>& adj,vector<bool>& vis,vector<ll>& W,vector<ll>& B,ll node)
{
    //cout<<"BEGIN"<<endl;
    //print(W);
    //print(B);
    vis[node] = true;
    list<ll> ngb = adj[node];

    if (ngb.empty())
    {
        W[node] = 1;
        B[node] = 1;

        /**
        cout<<"UPDATED"<<endl;
        print(W);
        print(B);
        **/

        return;
    }

    W[node] = 1;
    B[node] = 1;

    for (ll n:ngb)
    {
        if (!vis[n])
        {
            helper(adj,vis,W,B,n);
            ll new_B_n = (B[n]*W[node]) % MOD;
            ll new_B_node = (B[node]*W[n]) % MOD;

            ll new_W_n = ((W[n]*B[node])%MOD + (W[n]*W[node])%MOD)%MOD;
            ll new_W_node = ((W[node]*B[n])%MOD + (W[node]*W[n])%MOD)%MOD;

            W[n] = new_W_n;
            W[node] = new_W_node;

            B[n] = new_B_n;
            B[node] = new_B_node;
        }
    }
    /**
    cout<<"UPDATED"<<endl;
    print(W);
    print(B);
    **/

}

ll solve(vector<list<ll>>& adj)
{
    ll n = adj.size();
    vector<bool> visited(n);
    vector<ll> W(n);
    vector<ll> B(n);

    ll root = 0;
    helper(adj,visited,W,B,root);

    ll ans = (W[root] + B[root])%MOD;

    return ans;
}

int main()
{
    ll N;
    cin>>N;
    vector<list<ll>> adj(N);

    for (int i=0;i<N-1;++i)
    {
        ll from;
        ll to;
        cin>>from;
        cin>>to;
        --from;
        --to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    cout<<solve(adj)<<endl;

    return 0;
}
