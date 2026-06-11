#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll A, B, C;
    cin >> A >> B;
    if((A * B) % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}