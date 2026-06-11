#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */

int main(){
    int N; cin >> N;
    char s[1000];
    int i = 0;
    while(abs(N) > 0){
        s[i] = '0' + ((N % -2 == 0) ? 0 : 1);
        N = (N - ((N % -2 == 0) ? 0 : 1)) / -2;
        ++i;
    }
    if(i == 0)cout << 0;
    while(i > 0){
        cout << s[--i];
    }
}
