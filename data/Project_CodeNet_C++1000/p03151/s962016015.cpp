#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(ll N, vector<ll> A, vector<ll> B)
{
    ll ans = 0;
    ll need = 0;
    vector<ll> beyond;
    for(int i=0;i<A.size();++i)
    {
        if(A[i] < B[i])
        {
            ans++;
            need += B[i] - A[i];
        }else
        {
            if(A[i] > B[i])
            {
                beyond.push_back(A[i]-B[i]);
            }
        }
    }
    sort(beyond.begin(),beyond.end(),greater<int>());
    for(int i=0;i<beyond.size() && need > 0;++i)
    {
        need-=beyond[i];
        ans ++;
        if(need < 0)
        {
            break;
        }
    }
    if(need > 0)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}


int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0 ; i < N ; i++)
    {
        cin >> A[i];
    }
    vector<ll> B(N);
    for(int i = 0 ; i < N ; i++)
    {
        cin >> B[i];
    }
    solve(N, move(A), move(B));
    return 0;
}
