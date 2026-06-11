#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
#define PI  3.14159265358979323846264338327950
 
 
int main () {
    int N, K;
    cin >> N >> K;

    vector<int>A(N);
    rep(i,N) cin >> A[i];

    vector<int>baketto(N,0);
    rep(i,N){
        baketto[A[i]-1] +=1;
    }

    sort(baketto.begin(),baketto.end());

    int kazu =0;
    for(auto b : baketto){
        if(!b == 0) kazu +=1; 
    }

    if (kazu <= K) {
        cout << 0 << endl;
        return 0;
    
    }else{
        int ans=0;
        for(int i = N-kazu; kazu > K ;i++){
            ans += baketto[i];
            kazu -=1;
        }
        cout  << ans << endl;

    }

}
