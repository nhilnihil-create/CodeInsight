#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int count=0;
    rep(i, a+1){
        rep(j, b+1){
            rep(k, c+1)
            if(x == 500*i + 100*j + 50*k) count++;

        }
    }
    out(count);
}