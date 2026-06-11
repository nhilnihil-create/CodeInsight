#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 1e+5;
int s[MAX], t[MAX], c[MAX];

int main(){
    int n, maxc;
    cin >> n >> maxc;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i] >> c[i];
    }

    int nn = 2 * MAX + 1;
    vector<int> sm(nn, 0);
    for(int i = 1; i <= maxc; i++){
        vector<int> tt(nn, 0);
        for(int j = 0; j < n; j++){
            if(c[j] == i){
                tt[2*s[j]-1]++;
                tt[2*t[j]]--;
            }
        }
        for(int j = 0; j < nn-1; j++){
            tt[j+1] += tt[j];
        }
        for(int j = 0; j < nn; j++){
            if(tt[j] > 0) sm[j]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < nn; i++){
        if(ans < sm[i]) ans = sm[i];
    }
    cout << ans << endl;
    return 0;
}