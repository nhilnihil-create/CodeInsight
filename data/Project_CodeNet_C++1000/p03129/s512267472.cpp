#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    if(2*k-1 <= n) cout << "YES" << endl;
    else cout << "NO" << endl;
}