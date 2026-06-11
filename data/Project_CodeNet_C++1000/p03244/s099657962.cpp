#include <iostream>    // cin, cout
#include <string>    // string, stoi, to_string
#include <algorithm>    // sort, lower_bound, heap, min, next_permutation 
#include <functional>    // greater, less
#include <vector>    // vector
#include <stack>    // stack
#include <queue>    // queue
#include <list>    // list
#include <map>    // map
#include <set>    // set
#include <tuple>    // tuple
#include <bitset>    // bitset
#include <cstdio>  // fopen, printf, scanf, puts
#include <cmath>    // sin, exp, log, pow, sqrt
#include <iomanip>    // setfill, setbase

using namespace std;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<30));
const long long linf = (1LL<<60);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n/2), b(n/2);
    vector<int> ac(100001), bc(100001);
    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            cin >> a.at(i/2);
            ac.at(a.at(i/2))++;
        }
        else
        {
            cin >> b.at(i/2);
            bc.at(b.at(i/2))++;
        }
    }
    int maxa = 0, maxb = -1, maxa2 = 0, maxb2 = -1, ansa, ansb;
    for(int i=1; i<100001; i++)
    {
        if(ac.at(i) > maxa)
        {
            maxa2 = maxa;
            maxa = ac.at(i);
            ansa = i;
        }
        else if(ac.at(i) > maxa2) maxa2 = ac.at(i);
        if(bc.at(i) > maxb)
        {
            maxb2 = maxb;
            maxb = bc.at(i);
            ansb = i;
        }
        else if(bc.at(i) > maxb2) maxb2 = bc.at(i);
    }
    if(ansa != ansb) cout << n - maxa - maxb << endl;
    else cout << min(n - maxa2 - maxb, n - maxa - maxb2) << endl;
    return 0;
}
