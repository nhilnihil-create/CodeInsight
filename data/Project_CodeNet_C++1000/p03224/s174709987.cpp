#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;

int MOD = 1000000007;
int n;

signed main(){

    cin >> n;
  if(n==1){
    cout << "Yes" << endl;
    cout << 2 << endl;
    cout << "1 1" << endl;
    cout << "1 1" << endl;

    
    return 0;
  }

    int k = -1;
    rep(i,n+1){
        if(i*(i-1)/2 == n){
            k = i;
            break;
        }
        if(i == n){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    cout << k << endl;

    rep(i,k){
        cout << k-1 << " " ;
        int cnt = 0;
        int now1 = 0;
        int now2 = 0;
        while(cnt != k-1){
            if(now1 == i){
                rep(j,k-1-now1){
                    cout << j+1+now2 << " ";
                    cnt = k-1;
                }
            }else{
                cout << (now2 +k-1 -now1) - (k-1-i) << " ";
                now2 += k-1-now1;
                now1++;
                cnt++;
            }
        }

        cout << endl;
    }
    
    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 