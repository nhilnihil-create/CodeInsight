#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long long N;
    cin >> N;

    long long m = 0;
    long long a = 0;
    long long r = 0;
    long long c = 0;
    long long h = 0;

    vector<string> S(N);
    for (long long i = 0; i < N; i++) {
        cin >> S.at(i);
        char s = S.at(i).at(0);
        switch (s) {
            case 'M':
            m++;
            break;
            case 'A':
            a++;
            break;
            case 'R':
            r++;
            break;
            case 'C':
            c++;
            break;
            case 'H':
            h++;
        }
    }

    long long  ans = m * a * r + m * a * c + m * a * h + m * r * c + m * r * h + m * c * h
        + a * r * c + a * r * h + a * c * h
        + r * c * h;
    cout << ans << endl;

    


}
