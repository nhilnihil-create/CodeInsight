#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    if (S.size()==3) reverse(S.begin(),S.end());
    cout << S << '\n';
}