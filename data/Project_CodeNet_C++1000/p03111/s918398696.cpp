#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n,a,b,c;cin >> n >> a >> b >> c;
    vi l(n);
    rep(i,n) cin >> l[i];
    int ans = INF;
    for(int i=0;i<(1<<n);++i){
        bitset<8> one(i);
        for(int j=0;j<(1<<n);++j){
            bitset<8> two(j);
            int A = 0, B = 0, C = 0;
            int Acount = 0, Bcount = 0, Ccount = 0;
            for(int k=0;k<n;++k){
                if(one.test(k) && two.test(k)){
                    A += l[k];
                    ++Acount;
                }else if(one.test(k) && !two.test(k)){
                    B += l[k];
                    ++Bcount;
                }else if(!one.test(k) && two.test(k)){
                    C += l[k];
                    ++Ccount;
                }
            }
            if(Acount==0 || Bcount==0 || Ccount==0) continue;
            --Acount;--Bcount;--Ccount;
            int tmp = (Acount + Bcount + Ccount) * 10 + abs(A - a) + abs(B - b) + abs(C - c);
            chmin(ans, tmp);
        }
    }
    cout << ans << endl;
}