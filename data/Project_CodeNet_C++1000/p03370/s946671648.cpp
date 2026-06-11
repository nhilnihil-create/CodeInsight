#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forn1(i, n) for (ll i = 1; i <= n; i++)
#define EPS 1e-9
#define ff first
#define ss second
#define pb push_back
#define sortx(x) sort(x.begin(), x.end())

int main()
{
    ios::sync_with_stdio(0);

    ll N, X, soma = 0, menor=1000000;
    cin >> N >> X;
    ll vezes = N;
    vector<ll> custo(N);
    forn(i, N)
    {
        cin >> custo[i];
        soma+=custo[i];
        if(menor>custo[i]){
            menor=custo[i];
        }
    }
    vezes += (X-soma)/menor;
    cout << vezes << endl;

    return 0;
}