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

vector<ll> RUI_SORTED(ll N, vector<ll> A)
{
    vector<ll> ret(N);
    ret[0] = A[0];
    for(ll i=1;i<N;i++)
    {
        ret[i] = ret[i-1] + A[i];
    }
    sort(ALL(ret));
    return ret;
}

ll same_numbers(ll N, vector<ll> Rui_Sorted)
{
    ll total = 0;
    map<ll,ll> number_counter;
    for(auto x : Rui_Sorted)
    {
        number_counter[x]++;
    }
    number_counter[0]++;
    for(auto x : number_counter)
    {
        total += x.second * (x.second-1) / 2;
    }
    return total;
}

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    ALLIN1_NUMBER(A);

    vector<ll> Rui_sorted = RUI_SORTED(N,A);

    OUT0(same_numbers(N,Rui_sorted));

    return 0;
}