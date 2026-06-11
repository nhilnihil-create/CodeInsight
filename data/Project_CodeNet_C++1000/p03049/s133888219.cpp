#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pll = pair<long long,long long>;
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
//以上テンプレ

int main(){
    ll N;
    cin>>N;
    string S;
    ll count=0;
    ll a=0;
    ll b=0;
    ll ab=0;
    rep(i,N){
        ll n;
        cin>>S;
        n=S.size();
        if(S.at(n-1)=='A'&&S.at(0)=='B'){
            ab++;
        }else if(S.at(n-1)=='A'){
            a++;
        }else if(S.at(0)=='B'){
            b++;
        }
        rep(j,n-1){
            if(S.at(j)=='A'&&S.at(j+1)=='B'){
                count++;
            }
        }
    }
    if(ab==0){
        count+=min(a,b);
    }
    else if(b!=0||a!=0){
        count+=ab+min(a,b);
    }else{
        count+=ab-1;
    }
    cout<<count<<endl;
    }
