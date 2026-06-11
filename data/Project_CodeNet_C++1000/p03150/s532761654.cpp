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
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};



int main() {
    string s; cin >> s;
    if(s == "keyence"){cout << "YES" << endl; return 0;}
    int n = s.size();
    bool ok = false;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string S = "";
            for(int k = 0; k < i; k++){
                S += s[k];
            }
            for(int k = j+1; k < n; k++){
                S += s[k];
            }
            if(S=="keyence") ok = true;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO"  << endl;
}
