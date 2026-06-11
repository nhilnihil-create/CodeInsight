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
#define yn {puts("YES");}else{puts("NO");}
#define MAX_N 200005

int main() {
    int h,w,n;
    cin >> h >> w >> n;
    int x,y;
    cin >> x >> y;
    string a,b;
    cin >> a >> b;
    int flag = 0;

    int l = 1;
    int r = w;
    int u = 1;
    int d = h;

    drep(i,n){
        if(b[i] == 'L'){
            r++;
            if(r > w)r = w;
        }
        if(b[i] == 'R'){
            l--;
            if(l < 1)l = 1;
        }
        if(a[i] == 'L'){
            l++;
        }
        if(a[i] == 'R'){
            r--;
        }
        if(l > r){
            flag = 1;
            break;
        }

        if(b[i] == 'U'){
            d++;
            if(d > h)d = h;
        }
        if(b[i] == 'D'){
            u--;
            if(u < 1)u = 1;
        }
        if(a[i] == 'U'){
            u++;
        }
        if(a[i] == 'D'){
            d--;
        }
        if(u > d){
            flag = 1;
            break;
        }
    }

    //cout << u << ' ' << x << ' ' << d << endl;
    //cout << l << ' ' << y << ' ' << r << endl;
    
    if(flag == 0){
        if(y < l || r < y)flag = 1;
        if(x < u || d < x)flag = 1;
    }
    

    if(flag == 0)yn;
    return 0;
}
 
 
