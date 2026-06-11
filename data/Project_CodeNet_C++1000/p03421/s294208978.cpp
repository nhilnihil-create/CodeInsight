#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,A,B;
    cin >> N >> A >>B;
    if((N+A-1)/A > B || B>(N-A)+1){
        cout << -1 << endl;
        return 0;
    }
    ll loop = 0;
    while(N>0){
        ll maxB = loop + N;
        if(maxB < B +A){
            ll exceeded = maxB-B;
            for(int i=0;i <exceeded+1;i++){
                cout << N- exceeded +i << " ";
            }
            loop++;
            for(int i=0;i<B-loop;i++){
                cout << B-loop-i <<" ";
            }
            break;
        }
        for(int i=0;i<A;i++){
            cout << N-A +i+1 <<" ";
        }
        N-=A;
        loop++;
        
    }
    cout << endl;

    return 0;
}