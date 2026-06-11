#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include <map>
using namespace std;
typedef long long int ll;
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define all(u) u.begin(),u.end()
#define pl pair<ll,ll>
#define f first
#define s second
#define inf 1000000007





ll N;
double t[110];
double v[110];
double T[110];
vector<double> maxv(40040);

double min(double a, double b){
    if (a < b) return a;
    else return b;
}

int main() {
    cin >> N;
    rep(i,N) cin >> t[i+1];
    rep(i,N) cin >> v[i+1];
    v[0] = 0;
    v[N+1] = 0;
    t[0] = 0;
    t[N+1] = 0;
    rep(i,N){
        T[i+1] = T[i] + t[i+1];
    }
    rep(i,(2*T[N]+1)){
        rep(j,N+1){
            if (i*0.5 < T[j]){
                maxv[i] = v[j];
                break;
            }
        }
    }
    maxv[2*T[N]] = 0;
    maxv[0] = 0;
    repi(i,1,N){
        maxv[2*T[i]] = min(maxv[2*T[i]],min(maxv[2*T[i]-1],maxv[2*T[i]+1]));
    }
    // rep(i,2*T[N]+1) cout << i*0.5 << " " << maxv[i] << endl;
    for(ll i = 1; i <=2*T[N]; i++){
        maxv[i] = min(maxv[i],maxv[i-1]+0.5);
    }
    for(ll i = 2*T[N]-1; i>=0; i--){
        maxv[i] = min(maxv[i],maxv[i+1]+0.5);
    }
    // rep(i,2*T[N]+1){cout << i*0.5 << " " << maxv[i] << endl;}
    double ans = 0;
    rep(i,2*T[N]){
        ans += (maxv[i]+maxv[i+1])*0.25;
    }
    printf("%.9f\n",ans);
    return 0;
}
