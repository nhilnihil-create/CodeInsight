#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int x;
    cin >> x;
    int ans = 1;
    rep(i, 2, x+1){
        int j = i;
        while(true){
            j=j*i;
            if(j>x)break;
            ans = max(j,ans);
        }
    }
    cout << ans << endl;
}
