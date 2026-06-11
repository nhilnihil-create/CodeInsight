#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> l(Q), r(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> l[i] >> r[i];
    }
    
    vector<int> ac(N+1);
    ac[0] = 0;
    for (int i = 1; i < N; i++)
    {
        ac[i] = ac[i-1];
        if (S[i-1] == 'A' && S[i] == 'C')
        {
            ac[i]++;
        }
    }
    for (int i = 0; i < Q; i++)
    {
        cout << ac[r[i]-1] -ac[l[i]-1] << endl; 
    }
    
}

int main() {
    solve();
    return 0;
}