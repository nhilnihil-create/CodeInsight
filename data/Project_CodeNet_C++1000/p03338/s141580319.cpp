#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    string S,A,B;
    ll N ,ans = 0;
    cin >> N;
    cin >> S;

    for(ll i = 1; i < N; i++){
        ll tmp_ans = 0;
        vector<ll> a(26,0);
        vector<ll> b(26,0);
        
        A = S.substr(0,i);
        B = S.substr(i, N - i);

        for(int j = 0; j < i; j++) a[A[j] - 'a']++;
        for(int j = 0; j < N - i; j++) b[B[j] - 'a']++;


        for(int j = 0; j < 26; j++){
            if(a[j] > 0 && b[j] > 0) tmp_ans++;
        }
        ans = max(tmp_ans, ans);
    }
    cout << ans << endl;

}
