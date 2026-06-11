#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    vector<ll> h(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>h[i];
    int cx,cy;
    ll hh;
    bool flag=false;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            bool f=true;
            for(int m=0;m<n;m++){
                if(h[m]>0){
                    hh=h[m]+abs(x[m]-j)+abs(y[m]-i);
                    break;
                }
            }
            for(int m=0;m<n;m++){
                ll hsub=hh-abs(x[m]-j)-abs(y[m]-i);
                hsub=max(hsub,(ll)0);
                if(hsub==h[m]) continue;
                f=false;
                break;
            }
            if(f){
                cx=j;
                cy=i;
                flag=true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<cx<<" "<<cy<<" "<<hh<<endl;

}