#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;cin>>s>>t;
    vector<int> cha1(26, -1), cha2(26,-1);
    bool ans = true;
    for(int i=0; i<s.size(); i++){
        int S = s[i] - 'a', T = t[i] - 'a';
        if(cha1[S]==T&&cha2[T]==S)continue;
        else if(cha1[S]==-1&&cha2[T]==-1){
            cha1[S]=T, cha2[T]=S;
        }else{
            ans = false;
            break;
        }

    }
    cout<<(ans?"Yes":"No");
    return 0;
}