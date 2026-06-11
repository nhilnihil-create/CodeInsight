#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int A,B,K;
    cin>>A>>B>>K;
    int count = 0;
    for(int i=max(A,B); i>=1; i--){
        if(A%i==0 && B%i==0){
            count++;
        }

        if(count == K){
            cout << i << endl;
            return 0;
        }
    }
}
