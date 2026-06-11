#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
const int maxn = 8080 * 2;
bitset<maxn> mp;
int main(){
    string s;
    cin >> s;
    vector<int> t[2];
    int p = 0, curx = maxn/2, cury = maxn/2;
    while(p < s.size() && s[p] == 'F') curx++, p++;
    int tot = 0, m = 1;
    for(int e = p; e < s.size(); e++){
        if(s[e] == 'T'){
            t[m].push_back(tot);
            // cout << m << " " << tot << endl;
            tot = 0;
            m ^= 1;
        } else {
            tot++;
        }
    }
    // cout << m << " " << tot << endl;
    t[m].push_back(tot);
    mp.reset();
    mp.set(curx);
    for(int v : t[1]){
        mp = (mp<<v)|(mp>>v);
    }
    int xx, yy;
    cin >> xx >> yy;
    xx += maxn / 2;
    yy += maxn / 2;
    if(mp.test(xx));
    else return ! printf("No\n");
    mp.reset();
    mp.set(cury);
    for(int v : t[0]){
        mp = (mp<<v)|(mp>>v);
    }
    if(mp.test(yy));
    else return ! printf("No\n");
    printf("Yes\n");
    return 0;
}
