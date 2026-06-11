#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N; string S;
    cin >> N >> S;
    int C = count(S.begin()+1, S.end(), 'E');
    int min_count = C;

    for(int i=1; i<S.size(); i++) {
        if(S[i] == 'E') C--;
        if(S[i-1] == 'W') C++;
        min_count = min(min_count, C);
    }
    cout << min_count << endl;
}