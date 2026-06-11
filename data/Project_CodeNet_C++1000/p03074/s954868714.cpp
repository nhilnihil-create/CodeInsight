#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

#define INF  -10000000000

int main()
{
    int n,k;
    string s;
    vector<pair<int,int>> p;
    
    cin >> n >> k;
    cin >> s;
    
    int st,en;
    int m = 0;
    for (int i = 0;i < n;i++){
        if (i == 0){
            if (s[i] == '0'){
                st = 0;
                m = 1;
            }
        }
        if (i >= 1 && s[i-1] == '1' && s[i] == '0'){
            st = i;
            m = 1;
        }
        if (i >= 1 && s[i-1] == '0' && s[i] == '1'){
            en = i-1;
            p.push_back(make_pair(st,en));
            m = 0;
        }
    }
    if (m == 1){
        p.push_back(make_pair(st,n-1));
    }
    
    if (p.size() <= k){
        cout << n << endl;
    }
    else {
        int ans = -1;
        int res;
        for (auto i = 0;i <= p.size()-k;i++){
            if (i == 0){
                res = p[k+i].first;
            }
            else if (i == p.size()-k){
                res = n-p[i-1].second-1;
            }
            else {
                res = p[k+i].first-p[i-1].second-1;
            }
            ans = max(ans,res);
        }
        cout << ans << endl;
    }
    
}
