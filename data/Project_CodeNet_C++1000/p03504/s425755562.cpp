#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;

int N,C;
int s[100005],t[100005], c[100005];
int tm[31][100005];
int mx[31];

int main(){
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> s[i] >> t[i] >> c[i];
        for(int j = s[i]; j <= t[i]; j++)
            tm[c[i]][j] = 1;
        mx[c[i]] = max(t[i], mx[c[i]]);
    }

    int mx = 0;
    for(int i = 1; i <= 100005; i++){
        int cnt = 0;
        for(int j = 1; j <= C; j++){
            if(tm[j][i] == 1) cnt++;
        }
        mx = max(mx, cnt);
    }
    cout << mx << endl;
}

