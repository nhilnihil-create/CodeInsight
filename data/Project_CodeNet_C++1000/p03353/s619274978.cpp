#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    string s;
    int K;
    cin >> s >> K;

    vector<string> strings;

    rep(i,s.length()) {
        for (int j = 1; j <= K; j++) {
            strings.push_back(s.substr(i, j));
        } 
    }

    sort(strings.begin(), strings.end());

    int i = 0;
    int n = 1;
    while (i < strings.size()) {
        if (n == K) {
            cout << strings[i] << endl;
            return 0;
        }
        i++;
        if (strings[i] != strings[i - 1]) n++;
    }
    
    return 0;
}