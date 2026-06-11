#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const string emp = "Vacant";
const string M = "Male";
const string F = "Female";
 
void out(int N, string &S) {
    cout << N << endl;
    fflush(stdout);
    cin >> S;
    return;
}
 
int main() {
    int N;
    cin >> N;
    int L = 0, R = N;
    string Sl, Sr;
    out(0, Sl);
    if (Sl == emp) return 0;
    
    while (abs(L-R) > 1) {
        int mid = (L + R) / 2;
        string Sm;
        out(mid, Sm);
        if (Sm == emp) return 0;
        if ((abs(mid-L) % 2 == 0 && Sl != Sm) || (abs(mid-L) % 2 == 1 && Sl == Sm)) {
            R = mid; Sr = Sm;
        } else {
            L = mid; Sl = Sm;
        }
    }
    
    return 0;
}
