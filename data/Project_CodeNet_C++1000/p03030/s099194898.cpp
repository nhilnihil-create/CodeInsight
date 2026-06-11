#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {
    int n; cin >> n;
    vector<string> s(n),c(n);
    vector<int> p(n),w(101);
    priority_queue<int> t;

    rep(i,n){
        cin >> s[i] >> p[i];
        c[i] = s[i];
        w[p[i]] = i;
    }

    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());

    rep(i,s.size()){
        rep(j,c.size()){
            if(s[i] == c[j]) t.push(p[j]);
        }
        while(! t.empty()){
            cout << w[t.top()]+1 << endl;
            t.pop();
        }
    }

    return 0;
}









