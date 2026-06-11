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
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main() {
    string s; cin >> s;
    int n = s.size();
    int i = 0, j = n-1,ans = 0;

    while(i < j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else{
            if(s[i] == 'x'){
                ans++;
                i++;
            }else if(s[j] == 'x'){
                ans++;
                j--;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}