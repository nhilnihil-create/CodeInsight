#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    string S;
    cin >> S;
    N = S.size();
    ll cnt = 0;
    ll l = 0;
    ll r = N-1;
    while(l <= r){
        if(S[l] != S[r]){
            if(S[l] == 'x'){
                cnt++;
                l++;

            }else if(S[r] == 'x'){
                cnt++;
                r--;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else{
            l++;
            r--;
        }
    }
    cout << cnt << endl;
}