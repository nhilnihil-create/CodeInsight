#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int N;
    vector<string> s;

    cin >> N;
    s.resize(N);
    int aend = 0;
    int bbegin = 0;
    int ab = 0;
    int count = 0;
    rep(i, N) {
        cin >> s[i];
        
        if (s[i][0] == 'B' && s[i].back() == 'A') ab++;
        else if (s[i][0] == 'B') bbegin++;
        else if (s[i].back() == 'A') aend++;
        
        int k = 0;
        while (true) {
            int pos = s[i].find("AB", k);
            if (pos != string::npos) {
                count++;
                k = pos + 2;
                if (k >= s[i].size()) break;
                continue;
            }
            break;
        }
    }

    count += max(ab - 1, 0);
    if (ab > 0 && aend >= 1) {
        count++;
        aend--;
    }
    if (ab > 0 && bbegin >= 1) {
        count++;
        bbegin--;
    }
    int abmin = min(aend, bbegin);
    count += abmin;
    
    cout << count << endl;


    return 0;
}