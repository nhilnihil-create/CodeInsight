#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    rep(i, n, 1000){
        if(i % 111 == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}