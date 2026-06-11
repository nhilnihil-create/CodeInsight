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

class Query
{
    public:
    ll l,r;
};

void ALLIN_QUERIES(vector<Query>& Qs)
{
    for(auto& x : Qs)
    {
        cin >> x.l >> x.r;
    }
}

bool PRIME(ll N)
{
    if(N==1) return false;
    ll N_copy = N;
    for(ll i=2;i*i<=N;i++)
    {
        while(N_copy%i==0)
        {
            N_copy /= i;
        }
    }
    if(N_copy==N) return true;
    return false;
}

vector<bool> PRIME_OR_NOT()
{
    vector<bool> ret((1e5)+1);
    ret[0] = false;
    for(ll i=1;i<=1e5;i++)
    {
        if(PRIME(i))
        {
            ret[i] = true;
        }
        else
        {
            ret[i] = false;
        }
    }
    return ret;
}

vector<ll> RUI_SIMILAR_2017(vector<bool> Prime_Or_Not)
{
    vector<ll> ret((1e5)+1,0);
    ret[1] = 0;
    for(ll i=3;i<=1e5;i+=2)
    {
        if(Prime_Or_Not[i] && Prime_Or_Not[(i+1)/2])
        {
            ret[i] = ret[i-2] + 1;
        }
        else
        {
            ret[i] = ret[i-2];
        }
        ret[i-1] = ret[i-2];
    }
    return ret;
}

void Ans(vector<Query> Qs, vector<ll> Rui_Similar_2017)
{
    for(auto x : Qs)
    {
        OUT0(Rui_Similar_2017[x.r]-Rui_Similar_2017[x.l-1]);
    }
}

int main()
{
    ll Q;
    cin >> Q;

    vector<Query> Qs(Q);
    ALLIN_QUERIES(Qs);

    Ans(Qs,RUI_SIMILAR_2017(PRIME_OR_NOT()));

    return 0;
}