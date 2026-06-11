#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <tuple>
#define ll long long
using namespace std;
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;

int main()
{
    vector<ll>a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    vector<ll> b(10,0);
    for (ll i = 0; i < 4;i++){
        b[a[i]]++;
    }
    if(b[1]>0&&b[9]>0&&b[7]>0&&b[4]>0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
