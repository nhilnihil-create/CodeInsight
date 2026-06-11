#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


struct store
{
    ll can;
    ll price;
};
bool compare( struct store a , struct store b)
{
    return a.price< b.price;
}
int main()
{
    ll n;
    cin>>n;
    ll m;
    cin>>m;

    store* shop = new store[n];
    for(ll i=0; i < n; i++)
    {
        cin>>shop[i].price>>shop[i].can;
    }
    sort( shop , shop +n , compare);
//    for(int i=0;i<n;i++)
//    {
//        cout<<shop[i].price <<" "<<shop[i].can<<endl;
//    }
    ll index =0;
    ll ans =0;
    while( m>0)
    {
        if( m> shop[index].can )
        {
            m = m-shop[index].can;
            ans += shop[index].can*shop[index].price;
        } else
        {

            ans += m*shop[index].price;
            m =0;
        }
        index++;
    }
    cout<<ans;
}