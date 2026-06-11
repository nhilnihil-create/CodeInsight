#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};


int main() {
    int n,ans = 0; cin >> n;
    string s; cin >> s;

    int ala[26],alb[26];

    for(int i = 1; i < n; i++){
        rep(k,26) {ala[k] = 0; alb[k] = 0;}
        int cnt = 0;
        for(int j = 0; j < i; j++){
            ala[(int) s[j] - 97]++;
        }
        for(int j = i; j < n; j++){
            alb[(int) s[j] - 97]++;
        }

        for(int j = 0; j < 26; j++){
            if(ala[j] && alb[j]) cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}
