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
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int  N,M;
    cin >> N >> M;
    vector<int> L(M);
    vector<int> R(M);
    int min_R;
    int max_L;
    for(int i=0;i<M;i++){
        cin >> L[i] >> R[i];
    }
    for(int i=0;i<M;i++){
        if(i==0){
            min_R = R[i];
            max_L = L[i];
        }
        else if(min_R > R[i]){
            min_R = R[i];
        }
        else if(max_L < L[i]){
            max_L = L[i];
        }
    }
    int ans;
    ans = min_R - max_L + 1;
    if(ans<=0){
        ans = 0;
    }
    cout << ans << endl;
    
}