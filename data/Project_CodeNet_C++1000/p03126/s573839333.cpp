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
    ll M;  cin>>M;
    ll jma, a;
    VL ans(M,0);
    rep(i,0,N){
        cin>>jma;
        rep(j,0,jma){
            cin>>a;
            ans[a-1]++;
        }
    }

    ll sum=0;
    rep(i,0,M){
        if(ans[i]==N)sum++;
    }
    cout<<sum<<endl;
    return 0;
}