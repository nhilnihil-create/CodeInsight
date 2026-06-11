#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    string S; cin >> S;
    int cnt = 0;
    for(auto ch : S) if(ch == 'o') cnt++;
    cout << 700 + 100*cnt << endl;
}
