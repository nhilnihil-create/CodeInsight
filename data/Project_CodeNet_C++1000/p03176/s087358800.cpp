#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;
typedef long long int ll;

class SegmentTree
{
public:
    vector<ll> t;
    ll n;

    SegmentTree(ll n)
    {
        this->t.resize(2*n);
        this->n = n;

        //this->print();
    }

    void print()
    {
        for (auto i: this->t)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void add(ll pos,ll d)
    {
        ll node = pos + n;
        t[node]  = d;
        node /= 2;

        while (node >= 1)
        {
            t[node] = max(t[2*node],t[2*node + 1]);
            node /= 2;
        }

        //this->print();
    }

    ll get_max(ll a,ll b)
    {
        a += n;
        b += n;

        //cout<<a<<" "<<b<<endl;
        ll ans = 0;

        while (a <= b)
        {
            if (a%2) ans = max(ans,t[a++]);
            if (b%2 == 0) ans = max(ans,t[b--]);

            a /= 2;
            b /= 2;
        }

        return ans;
    }
};


ll solve(vector<ll>& H,vector<ll>& B)
{
    ll n = H.size();

    ll st_h = pow(2,ceil(log2(n+1)));
    SegmentTree* st = new SegmentTree(st_h);
    //dp[i] = max beauty with height == i

    for (ll i=0;i<n;++i)
    {
        ll my_h = H[i];
        ll best = st->get_max(0,my_h - 1);
        st->add(my_h,best + B[i]);

        //cout<<i<<"DOn"<<endl;
    }

    //return 9;
    return st->get_max(0,n);

}


int main()
{
    ll N;
    cin>>N;
    vector<ll> H(N);
    vector<ll> B(N);

    for (ll i=0;i<N;++i)
    {
        cin>>H[i];
    }


    for (ll i=0;i<N;++i)
    {
        cin>>B[i];
    }


    cout<<solve(H,B)<<endl;

    return 0;
}
