#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main() {
    int N, Q; cin >> N >> Q;
    string S, k; cin >> k;
    S = "0" + k + "0";
    string T, D;
    for(int i=0; i<Q; i++){
        char t, d; cin >> t >> d;
        T += t;
        D += d;
    }
    
    int L = 1;
    int R = N;
    for(int i=Q-1; i>=0; i--){
        int nl = L;
        int nr = R;
        if(S[nl]==T[i] && D[i]=='L') L++;
        if(S[nl-1]==T[i] && D[i]=='R') L--;
        if(S[nr]==T[i] && D[i]=='R') R--;
        if(S[nr+1]==T[i] && D[i]=='L') R++;
    }
    cout << max(R - L + 1, 0) << endl;
    return 0;
}

