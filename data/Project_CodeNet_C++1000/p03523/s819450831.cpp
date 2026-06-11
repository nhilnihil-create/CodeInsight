#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    
    if (S.size() < 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (S[0] != 'A')
    {
        S.insert(0, "A");
    }
    if (S.size() < 4)
    {
        cout << "NO" << endl;
        return;
    }
    if (S[4] != 'A')
    {
        S.insert(4, "A");
    }
    if (S.size() < 6)
    {
        cout << "NO" << endl;
        return;
    }
    if (S[6] != 'A')
    {
        S.insert(6, "A");
    }
    if (S.size() < 8)
    {
        cout << "NO" << endl;
        return;
    }
    if (S[8] != 'A')
    {
        S.insert(8, "A");
    }
    
    
    
    if (S == "AKIHABARA")
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
}

int main() {
    solve();
    return 0;
}