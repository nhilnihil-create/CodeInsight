#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,K;
    cin >> A >> B >> K;
    int N=min(A,B);
    int M=max(A,B);
    int ans;
    for(int i=1; i<N+1; i++){
        if(M%(N-i+1)==0 && N%(N-i+1)==0) K--;
        if(K==0){
            ans=N-i+1;
            break;
        }

    }
    cout << ans << endl;
}