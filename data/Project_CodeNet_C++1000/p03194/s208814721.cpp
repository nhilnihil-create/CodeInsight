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
using namespace std;
typedef long long int ll;

int main() {
    ll N,P;
    scanf("%lld%lld",&N,&P);
    double c;
    double cc = 1.0/N;
    c = pow(P,cc);
    ll d;
    d = c;
    ll ans = 1;
    for (ll i=d+5;i>=1;i--){
        long double D;
        D = pow(i,N);
        ll DD;
        DD = D;
        if (P % DD == 0){
            ans = i;
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
