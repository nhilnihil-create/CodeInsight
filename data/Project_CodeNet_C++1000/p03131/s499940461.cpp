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
    ll K,A,B;
    cin>>K>>A>>B;
    ll Ans=0;
    if(B-A<3){
        cout<<K+1<<endl;
    }else if(K<=A){
        cout<<K+1<<endl;
        }else{
            ll a=K-A+1;
            Ans=a/2*(B-A)+A;
            if(a%2==1){
                Ans+=1;
            }
            cout<<Ans<<endl;
        }
    }
