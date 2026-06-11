#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    ll d ,n;
    cin >> d >> n;
    if(d == 0) {
        if(n<=99) cout << n << endl;
        else cout << n+1 << endl;
    } else if (d == 1) {
        if(n<=99) cout << n*100 << endl;
        else cout << (n+1)*100 << endl;
    } else {
        if(n<=99) cout << n*10000 << endl;
        else cout << (n+1)*10000 << endl;
    }
    return 0;
}
