#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 110000

int f[MAX_N];

int main() {
    int n;
    cin >> n;

    if(n==100000){
        cout << '1' << endl;
        return 0;
    }

    rep(i,MAX_N){
        f[i] = 46;
    }
    f[0] = 0;
    queue<P> que;
    f[n] = 0;
    srep(i,1,10){
        if((n*i)%10 < f[n*i/10]){
            f[n*i/10] = (n*i) % 10;
            que.push(P((n*i/10),(n*i) % 10));
        }
    }

    while(que.size() > 0){
        P p = que.front();
        que.pop();
        rep(i,10){
            int a = (n*i + p.first) / 10;
            int b = (n*i + p.first) % 10 + p.second;
            if(b < f[a]){
                f[a] = b;
                que.push(P(a,b));
            }
        }
    }

    int ans = 999;

    srep(i,1,100000){
        int tmp = f[i];
        int ii = i;
        rep(j,5){
            tmp += ii % 10;
            ii /= 10;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
 
 
