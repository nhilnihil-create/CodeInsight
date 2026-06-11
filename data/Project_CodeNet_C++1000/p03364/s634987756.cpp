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
    char s[n][n];
    rep(i,n){
        scanf("%s", s[i]);
    }

    int ans = 0;
    char t[n][n];
    
    rep(i,n){
        rep(j,n){
            rep(k,n){
                t[j][k] = s[j][(k + i)%n];
            }
        }
        int flag = 1;
        rep(j,n){
            rep(k,n){
                if(t[j][k] != t[k][j]){
                    flag = 0;
                    break;
                }
            }
        }
        ans += (n - i) * flag;
    }

    srep(i,1,n){
        rep(j,n){
            rep(k,n){
                t[j][k] = s[(j + i)%n][k];
            }
        }
        int flag = 1;
        rep(j,n){
            rep(k,n){
                if(t[j][k] != t[k][j]){
                    flag = 0;
                    break;
                }
            }
        }
        ans += (n - i) * flag;
    }

    cout << ans << endl;
    return 0;
}
 
 
