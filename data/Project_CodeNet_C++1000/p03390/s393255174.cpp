#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;

int n;
ll a[200010];
ll b[200010];

int main ()
{
    cin >> n;
    REP(i,n) cin >> a[i] >> b[i];

    REP(i,n) {
        ll sq  = (ll)sqrt(a[i] * b[i]);
        ll ans = (a[i] * b[i] - (a[i] != b[i])) / sq + sq - 2;
        cout << ans << endl; 
    }

    return 0;
}