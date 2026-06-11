#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <climits>
#include <unordered_map>
#include <numeric>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<int>a(h+1,1<<30);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        a[x] = min(a[x],y);
    }
    int pos = 1;
    for(int i = 2; i <= h; i++){
        if(a[i]<=pos){
            cout << i-1 << endl;
            return 0;
        }
        if(a[i] != pos+1){
            pos++;
        }
    }
    cout << h << endl;
    return 0;
}
