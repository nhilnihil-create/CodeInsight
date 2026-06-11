#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

void ALLOUT_NUMBER(vector<ll> V)
{
    ll N = V.size();
    for(ll i=0;i<N;i++)
    {
        cout << V[i];
        if(i<N-1) cout << ' ';
    }
    cout << endl;
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

class Shop
{
    public:
    ll open = 0;
};

void ALLIN_SHOPS(vector<Shop>& shops)
{
    for(auto& x : shops)
    {
        for(ll i=0;i<10;i++)
        {
            ll A; cin >> A;
            x.open += A<<(9-i);
        }
    }
}

void ALLOUT_SHOPS(vector<Shop> shops)
{
    for(auto x : shops)
    {
        OUT0(x.open);
    }
}

class Joisino_Shop
{
    public:
    vector<vector<ll>> P;
};

void ALLSET_J_SHOP(ll N, Joisino_Shop& J)
{
    J.P.resize(N);
    for(ll i=0;i<N;i++)
    {
        J.P[i].resize(11);
        for(auto& x : J.P[i])
        {
            cin >> x;
        }
    }
}

void ALLOUT_J_SHOP(Joisino_Shop J)
{
    for(auto x : J.P)
    {
        for(auto y : x)
        {
            cout << y << ' ';
        }
        cout << endl;
    }
}

ll Ans(ll N, Joisino_Shop J, vector<Shop> shops)
{
    ll max_gains = -1e10;
    for(ll i=1;i<1024;i++)
    {
        ll gains = 0;
        for(ll k=0;k<N;k++)
        {
            ll And_of_shopsk_i = (shops[k].open & i);
            ll bit_counter = 0;
            for(ll j=0;j<10;j++)
            {
                if(((And_of_shopsk_i)&(1<<j)) == (1<<j)) bit_counter++; 
            }
            gains += J.P[k][bit_counter];
        }
        max_gains = max(max_gains,gains);
    }
    return max_gains;
}

int main()
{
    ll N;
    cin >> N;

    vector<Shop> shops(N);
    ALLIN_SHOPS(shops);

    Joisino_Shop J;
    ALLSET_J_SHOP(N,J);

    OUT0(Ans(N,J,shops));

    return 0;
}