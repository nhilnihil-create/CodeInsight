#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    ll N; cin >> N;
    ll ans = 0;
    ll b=0, a=0;
    ll cnt=0;
    vector<string> V(N);
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        for(int j = 0; j < S.size()-1; j++){
            if(S[j] == 'A' && S[j+1] == 'B') ans++;
        }
        
        if(S[0] == 'B' && S[(int)S.size()-1] == 'A') cnt++;
        else if(S[0] == 'B') b++;
        else if(S[(int)S.size()-1] == 'A') a++;

    }
    ll c;
    if(cnt == 0) c = min(a, b);
    else {
        if(a+b>0) c = cnt+min(a, b);
        else{
            c = cnt-1;
        }
    }
    cout << ans + c << endl;

}