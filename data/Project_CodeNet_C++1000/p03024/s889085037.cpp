#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int n=S.size();
    int cnt=0;
    for (char c:S) cnt+=(c=='o');
    cout << (8<=cnt+(15-n)?"YES":"NO") << '\n';
}