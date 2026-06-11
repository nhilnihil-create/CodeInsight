#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    string N;
    cin >> N;
    int size = N.size();
    int max = 9*(size-1);
    int n = int (N[0] - '0');
    bool frg = false;
    for(int i=1;i<size;i++){
        if(N[i]!='9'){
            frg = true;
            break;
        }
    }
    int ans;
    if(frg){
        ans = max + (n-1);
    }
    else{
        ans = max + n;
    }
    
    cout << ans << endl;
}