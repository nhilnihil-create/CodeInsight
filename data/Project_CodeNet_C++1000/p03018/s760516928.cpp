#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    ll front = 0;
    ll ans =0;
    for(int i=0;i<N;i++){
        if(S[i] == 'A'){
            front++;
            continue;
        }
        if(i<N-1 && S[i] =='B' && S[i+1] == 'C'){
            ans += front;
            i++;
            continue;
        }
        front =0;
    }
    cout << ans << endl;

    return 0;
}