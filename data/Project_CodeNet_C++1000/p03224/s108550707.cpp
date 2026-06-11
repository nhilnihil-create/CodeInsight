#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

const int MAX_N = 301100;

ll ans[MAX_N];
int main(){
    ll N;
    cin >> N;

    ll wa = 0;
    ll k = 1;
    bool find = false;
    while(wa < MAX_N){
        wa += k;
        if(wa == N){
            find = true;
            break;
        }
        k++;
    }
    if(!find){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    printf("%lld\n",k+1);

    ll num = 1;
    vector<queue<ll> > q(k);
    for(ll i = 0; i <= k; i++){
        if(num <= N){
            for(ll x = 0; x < k-i; x++){
                ans[x] = num;
                q[i].push(num);
                num++;
            }
        }
            ll index = 0;
            for(ll x = 0; x < i; x++){
                ans[k-i+x] = q[index].front();
                q[index].pop();
                index++;
            }

        printf("%lld ", k);
        for(ll z = 0; z < k; z++){
            printf("%lld ", ans[z]);
        }
        printf("\n");
    }
    return 0;
}
