#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<complex>

using namespace std;

#define ll long long
#define ld long double
#define EPS 1e-9
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}

string s;
vs t,d;
int n,q;

int f(int ind){
    rep(i,q)if(t[i][0] == s[ind]){
        if(d[i] == "R")ind++;
        else ind--;
        if(ind == n || ind < 0)break;
    }
    return ind;
}

signed main(void) {
    cin >> n >> q;
    cin >> s;
    t = d = vs(q);
    rep(i,q)cin >> t[i] >> d[i];
    int ans = n;
    {
        int ok = -1, ng = n;
        while(ng - ok > 1){
            int mid = (ok+ng)/2;
            if(f(mid) == -1)ok = mid;
            else ng = mid;
        }
        ans -= ok - -1;
    }
    {
        int ok = n, ng = -1;
        while(ok - ng > 1){
            int mid = (ok+ng)/2;
            if(f(mid) == n)ok = mid;
            else ng = mid;
        }
        ans -= n - ok;
    }
    cout << ans << endl;
}
