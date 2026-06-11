#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;
#include <map>
#include <math.h>

using ll = long long;
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    if (n==2) out("Borys");
    else if((b-a)%2==0) out("Alice");
    else out("Borys");
}