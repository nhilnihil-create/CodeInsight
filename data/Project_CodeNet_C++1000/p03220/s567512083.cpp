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
    int n,t,a;
    cin >> n >> t >> a;
    int minN = 100000001;
    int p = 0;
    rep(i, 0, n){
        int x;
        cin >> x;
        int tmp = (t*1000 - x*6) - a*1000;
        if(tmp < 0) tmp = -tmp;
        if(minN > tmp){minN = tmp; p=i+1;}
    }
    cout << p << endl;
}
