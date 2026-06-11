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
#define fi first
#define se second
#define inf 1000000007
#define mp(a,b) make_pair(a,b)

ll N;
vector<ll> a(51);


int main() {
    ll MAX = -inf;
    ll MIN = inf;
    ll maxi;
    ll mini;
    cin >> N;
    rep(i,N) {
        cin >> a[i];
        if (a[i] > MAX){
            maxi = i+1;
            MAX = a[i];
        }
        if (a[i] < MIN){
            mini = i+1;
            MIN = a[i];
        }
    }
    if (MIN >= 0){
        cout << N-1 << endl;
        rep(i,N-1){
            cout << i+1 << " " << i+2 << endl;
        }
    }
    else if(MAX <= 0){
        cout << N-1 << endl;
        rep(i,N-1){
            cout << N-i << " " << N-i-1 << endl;
        }
    }
    else{
        if (abs(MIN) <= abs(MAX)){
            ll num = N-1;
            rep(i,N){
                if (a[i] < 0){
                    num++;
                }
            }
            cout << num << endl;
            rep(i,N){
                if (a[i] < 0){
                    cout << maxi << " " << i+1 << endl;
                }
            }
            rep(i,N-1){
                cout << i+1 << " " << i+2 << endl;
            }
        }
        else{
            ll num = N-1;
            rep(i,N){
                if (a[i] > 0){
                    num++;
                }
            }
            cout << num << endl;
            rep(i,N){
                if (a[i] > 0){
                    cout << mini << " " << i+1 << endl;
                }
            }
            rep(i,N-1){
                cout << N-i << " " << N-i-1 << endl;
            }
        }
    }
  
    
    return 0;
}
