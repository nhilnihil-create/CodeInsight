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
    ll N; cin>>N;
    ll flg=0;
    rep(i,0,26){
        rep(j,0,16){
            if(i==0&&j==0)continue;
            if(N%(4*i+7*j)==0){flg=1;break;}
        }
        if(flg==1)break;
    }
    cout<<(flg==1 ? "Yes":"No")<<endl;
}