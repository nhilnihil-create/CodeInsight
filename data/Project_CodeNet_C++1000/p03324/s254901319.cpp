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
 
int main(){
    ll D,N; cin>>D>>N;
    if(D==0){
        if(N!=100)cout<<N<<endl;
        else cout<<101<<endl;
    }
    if(D==1){
        if(N!=100)cout<<N*100<<endl;
        else cout<<10100<<endl;
    }
    if(D==2){
        if(N!=100)cout<<N*10000<<endl;
        else cout<<1010000<<endl;
    }
    return 0;
}