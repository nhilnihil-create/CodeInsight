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
    string s;
    cin >> s;
    if(s[0]!=s[1]&&s[1]!=s[2]&&s[2]!=s[0]) out("Yes");
    else out("No");
}
