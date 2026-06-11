#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printVector(vector<ll> vec){
    stringstream ss;
    for(ll i=0;i<vec.size();i++)
    {
        ss<<vec[i];
    }
    cout<<ss.str()<<endl;
}

int main()
{
    ll N,M;
    cin >> N >> M;
    if(M<=N)
    {
        cout<<0;
        return 0;
    }
    vector<ll> X(M,0);
    vector<ll> S(M-1,0);
    for(ll i=0;i<M;i++){
        cin>>X[i];
    }
    sort(X.begin(),X.end());
    for(ll i=1;i<M;i++)
    {
        S[i-1]=X[i]-X[i-1];
    }
    sort(S.rbegin(),S.rend());
    ll res=accumulate(S.begin(),S.end(),0);
    for(ll i=0;i<N-1;i++)
    {
        res-=S[i];
    }
    cout<<res; 
    return 0;
}