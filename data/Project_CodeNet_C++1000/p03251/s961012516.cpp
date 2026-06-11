#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(ll N, ll M, ll X, ll Y, vector<ll> x, vector<ll> y)
{
    ll maxx = x[0];
    for(ll t:x)maxx = max(maxx,t);
    ll miny = y[0];
    for(ll t:y)miny = min(miny,t);
    for(int t=X+1;t<=Y;++t)
    {
        if(t > maxx && t <= miny)
        {
            cout<<"No War"<<endl;
            return;
        }
    }
    cout<<"War"<<endl;
}


int main()
{
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    ll X;
    cin >> X;
    ll Y;
    cin >> Y;
    vector<ll> x(N);
    for(int i = 0 ; i < N ; i++)
    {
        cin >> x[i];
    }
    vector<ll> y(M);
    for(int i = 0 ; i < M ; i++)
    {
        cin >> y[i];
    }
    solve(N, M, X, Y, move(x), move(y));
    return 0;
}
