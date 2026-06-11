#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

int main(){
    ll N; cin >> N;
    ll l = 0, r = N, m;

    cout << 0 << endl;
    string S; cin >> S;
    if(S == "Vacant") return 0;
    /*cout << N-1 << endl;
    string _; cin >> _;
    if(_ == "vacant") return 0;*/

    while(1){
        m = (l+r)/2;
        cout << m << endl;
        string T; cin >> T;
        if(T == "Vacant") return 0;
        //if((m % 2 && S != T) || (m % 2 == 0 && S == T)) l = m+1;
        if((m % 2 == 0 && S == T) || (m % 2 == 1 && S != T)) l = m+1;

        else{
            r = m;
        }
    }
}