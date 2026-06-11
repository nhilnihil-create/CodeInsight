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
        string s; cin >> s;
        int n = s.size(),cnt = 0;
        if(s[0] != 'A') {
            cout << "WA" << endl;
            return 0;
        }
        int I;
        for(int i = 2;i < n- 1;i++){
            if(s[i] == 'C') {
                cnt++;
                I = i;
            }
        }
        if(cnt != 1){
            cout << "WA" << endl;
            return 0;
        }

        for(int i = 1;i < n;i++){
            if(i == I) continue;
            if(isupper(s[i])){
                cout << "WA" << endl;
                return 0;
            }
        }

        cout << "AC" << endl;
}