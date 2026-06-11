#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()


int main()
{
    ll N;  cin>>N;
    vector<long double> x(N);
    vector<string> u(N);
    long double sum=0;
    rep(i,0,N){
        cin>>x[i]>>u[i];
        if(u[i]=="JPY")sum += x[i];
        else if(u[i]=="BTC")sum += x[i]*380000.0;
    }
    cout<<fixed<<setprecision(15)<<sum<<endl;

}