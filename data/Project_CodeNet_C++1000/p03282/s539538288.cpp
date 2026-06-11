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
    string S;
    cin >> S;
    ll K;
    cin >> K;
    string ans;
    if(K <= (ll)S.size()){
        for(int i=0;i<(int)K;i++){
            if(S[i]!='1'){
                ans = S[i];
                break;
            }
            if(i==K-1){
                ans = S[i];
            }
        }
    }
    else{
        for(int i=0;i<(int)S.size();i++){
            if(S[i]!='1'){
                ans = S[i];
                break;
            }
        }
    }
    cout << ans << endl;
}