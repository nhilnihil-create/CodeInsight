#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;

int main(){
    string s,t; cin >> s >> t;
    s += s;
    int n = s.size(),N = t.size();

    for(int i = 0;i < n;i++){
        if(s[i] == t[0]){
            bool ok = true; int k = 0;
            for(int j = i;j < i + N;j++){
                if(s[j] == t[k]) {
                    k++;
                    continue;
                }
                ok = false;
            }if(ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}