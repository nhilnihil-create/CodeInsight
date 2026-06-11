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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    rep(i, 0, n-1){
        int dis2 = 0;
        map<char, int>sm,tm;
        
        rep(j, 0, i+1){
            sm[s[j]]++;
        }
        
        rep(j, i+1, n){
             if(sm[s[j]] && !tm[s[j]])dis2++;
             tm[s[j]]++;
        }
        ans = max(ans,dis2);
    }
    
    cout << ans << endl;
}
