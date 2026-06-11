#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1000000;
#include <map>
#include <math.h>
 
using ll = long long;
using namespace std;

ll n, k;
const ll mod = 1000000007;

int main(){
    string c1, c2;
    cin >> c1 >> c2;
    if(c1[0]==c2[2]&&c1[2]==c2[0]&&c1[1]==c2[1]) out("YES");
    else out("NO");
}
