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

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
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
typedef vector<pii> vp;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}


signed main(void) {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n)cin >> a[i];
    int ma = 0;
    rep(i,n)if(abs(a[ma]) < abs(a[i]))ma = i;
    vp v;
    rep(i,n)if(i!=ma){
        v.push_back(pii(ma,i));
        a[i] += a[ma];
    }
    //rep(i,n)cout << " " << a[i];cout << endl;
    if(a[ma] > 0){
        rep(i,n-1){
            v.push_back(pii(i,i+1));
            a[i+1] += a[i];
        }
    }else{
        for(int i = n-1; i > 0; i--){
            v.push_back(pii(i,i-1));
            a[i-1] += a[i];
        }
    }
    cout << v.size() << endl;
    rep(i,v.size())cout << v[i].first+1 << " " << v[i].second+1 << endl;
    //rep(i,n)cout << " " << a[i];cout << endl;
}
