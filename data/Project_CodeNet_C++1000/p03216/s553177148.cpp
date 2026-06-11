#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    int k_[q];
    rep(i,q)cin >> k_[i];
    rep(ite,q){
        ll ans = 0;
        int k = k_[ite];

        ll d = 0;
        ll m = 0;
        ll sum = 0;

        int now = n-1;
        int now2 = n;
        while(true){
            while(s[now] != 'C'){

                if(now2<=now && s[now] == 'D'){
                    d--;
                }

                if(now2<=now && s[now] == 'M'){
                    sum -= d;
                    m--;
                }

                now--;
                if(now<2)break;
            }
            if(now<2)break;

            ans += sum;

            if(now < now2){
                now2 = now;    
            }
            
            for(; max(0,now-k+1) <= now2; now2--){
                if(s[now2] == 'D'){
                    ans += m;
                    sum += m;
                    d++;
                }
                if(s[now2] == 'M'){
                    m++;
                }
            }
            now--;

        }


        cout << ans << endl;
    }

   

    return 0;
}
 
 
