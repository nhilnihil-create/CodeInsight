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
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int max_task;
    int count=abs(a1-a2)+abs(a2-a3)+abs(a3-a1);
    max_task = max({abs(a1-a2),abs(a2-a3),abs(a3-a1)});
    out(count-max_task);
}