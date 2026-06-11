#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int MAX = 101000;

int main() {
    int N;
    string s;
    cin >> N >> s;
    int westAc[N+1], eastAc[N+1];
    westAc[0]=0;
    eastAc[0]=0;
    for(int i=0;i<N;++i) {
        if(s[i] == 'W') {
            westAc[i+1] = westAc[i]+1;
            eastAc[i+1] = eastAc[i];
        }
        else {
            eastAc[i+1] = eastAc[i]+1;
            westAc[i+1] = westAc[i];
        }
    }
    int ans = N;
    for(int i=0;i<N;++i) {
        int c = westAc[i]+ (eastAc[N]-eastAc[i+1]);
        ans = min(ans, c);
    }
    cout << ans << endl;
}
