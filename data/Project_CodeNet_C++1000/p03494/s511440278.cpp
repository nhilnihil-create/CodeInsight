#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int i, N, judge=0, count=0;
    ll A[200];
    
    cin >> N;
    for(i=0; i<N;i++) cin >> A[i];
    
    for(;judge==0;count++){
        for (i = 0; i < N; i++) {
            if(A[i]%2==0) A[i]/=2;
            else {
                judge =1;
                break;
            }
        }
    }
    cout << count-1 << endl;
}