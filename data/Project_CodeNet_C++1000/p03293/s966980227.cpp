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
    string S,T;
    cin>>S>>T;
    bool flg=false;
    rep(i,0,S.size()){
        S.push_back(S[0]);
        S.erase(S.begin());
        if(S==T)flg=true;
    }
    cout<<(flg ? "Yes":"No")<<endl;
    return 0;
}