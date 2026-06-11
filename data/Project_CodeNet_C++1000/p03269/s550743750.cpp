#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

vector<int> niz;
vector<int> pniz;
vector<tuple<int, int, int>> res;
int n, duz;

void dabl()
{
    n++;
    res.pb(mt(n-1, n, duz));
    res.pb(mt(n-1, n, 0));
    duz *= 2;
}

void dodaj()
{
    res.pb(mt(1,n,duz));
    duz++;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l;
    cin >> l;
    while(l > 0) niz.pb(l%2), l/=2;

    for(int i = niz.size()-1; i >= 0; i--)
        pniz.pb(niz[i]);

    res.pb(mt(1,2,0));

    duz = 1;
    n = 2;

    for(int i = 1; i < pniz.size(); i++)
    {
        if(i == 1) dodaj();
        else dabl();
        if(pniz[i] == 1) dodaj();
    }
    cout << n << " " << res.size() << "\n";
    for(int i = 0; i < res.size(); i++)
        cout << get<0>(res[i]) << " " << get<1>(res[i]) << " " << get<2>(res[i]) << "\n";

    return 0;
}
