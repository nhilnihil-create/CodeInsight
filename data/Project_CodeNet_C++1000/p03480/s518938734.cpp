#include <bits/stdc++.h>

using ll = long long;
using namespace std;
constexpr ll inf = 1e15;
constexpr ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin>>S;

    char base = S[S.length()/2];
    for (int n = 1; n <= S.length() / 2; n++) {
        if (S[S.length()/2-n] != base || S[S.length()/2+n-(S.length()%2==0 ? 1 : 0)] != base) {
            cout<<(S.length()+1)/2+n-1<<endl;
            return 0;
        }
    }

    cout<<S.length()<<endl;

    return 0;
}