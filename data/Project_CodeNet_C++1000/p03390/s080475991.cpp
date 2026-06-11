#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int lim = 5;
ll a, b;
int q;

ll imax(ll X){
    ll lo = 1, mi, hi = sqrt(X) + 2;
    while(lo < hi){
        mi = (lo + hi + 1) >> 1;
        if(mi * (mi - 1) < X) lo = mi;
        else hi = mi - 1;
    }
    return lo;
}
ll mysol(ll a, ll b){
        if(a == 1 && b == 1){
            return 0;
        }
        ll ansa = 0, ansb = 0;
        ll k = imax(a*b-1);
        if(a > 1){
            if(a < lim){
                set<ll> S;
                for(int j = 1; j < a; j++) if((a*b-1)/j > b) S.insert((a*b-1)/j);
                ansa += S.size();
                S.clear();
            }else{
                if(k >= (a*b-1)) ansa += (a*b-1) - b;
                else if(k <= b){
                    ansa += (a*b-1)/(b+1);
                }else{
                    ansa += k - b + max(0LL, (a*b-1)/k - 1);
                    //printf("ans1 : %lld\n",k + max(0LL, (a*b-1)/k - (a*b-1)/(a+1)));
                }
            }
        }
        if(b > 1){
            if(b < lim){
                set<ll> S;
                for(int j = 1; j < b; j++) if((a*b-1)/j > a) S.insert((a*b-1)/j);
                ansb += S.size();
                S.clear();
            }else{
                if(k >= (a*b-1)) ansb += (a*b-1) - a;
                else if(k < a){
                    ansb += (a*b-1)/(a+1);
                }else{
                    ansb += k - a + max(0LL, (a*b-1)/k - 1);
                    //printf("ans1 : %lld\n",k + max(0LL, (a*b-1)/k - (a*b-1)/(a+1)));
                }
            }
        }
        //printf("a = %lld, b = %lld, k = %lld\n",a,b,k);
        //printf("ansa = %lld, ansb = %lld\n",ansa,ansb);
        //return ansa + ansb + min(a-1-ansa,b-1-ansb);
        return ansa + ansb;
}

ll sol2(ll a, ll b){
    if(a > b) swap(a,b);
    if(b <= a + 1) return a + a - 2;
    ll lo = 0, mi, hi = 2e9;
    while(lo < hi){
        mi = (lo + hi + 1) >>1;
        if(mi * mi < a * b) lo = mi;
        else hi = mi - 1;
    }
    ll c = lo;
    return c*(c+1) < a*b ? c + c - 1 : c + c - 2;
}

mt19937 g(0x95949);
uniform_int_distribution<int> d(1,1e9);

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(cin >> q; q--; ){
        cin >> a >> b;
        //a = d(g); b = a + 1;
        //if(mysol(a,b) == sol2(a,b)) continue;
        //cout << "mysol = " << mysol(a,b) << '\n';
        cout << sol2(a,b) << '\n';
    }
}
