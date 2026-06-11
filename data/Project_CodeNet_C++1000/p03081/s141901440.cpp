#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;
int main(int argc, const char * argv[]) {
    
    int n, q;
    cin >> n >> q;
    
    string s;
    cin >> s;

    vector<char> t(q);
    vector<char> d(q);
    for (int i=0; i<q; i++) {
        cin >> t[i] >> d[i];
    }

    int ll=-1, lr=n-1;
    int rl=0, rr=n;
    while(ll < lr) {
        int m=(lr+ll+1)/2;
        int md=m;
        bool v=false;
        for(int i=0; i<q; i++){
            if (t[i]!=s[md]) continue;

            if (d[i]=='L') md--;
            if (d[i]=='R') md++;
            if (md<=-1 || md>=n) {
                v=(md<=-1);
                break;
            }
        }
        if (v){
            ll=m;
        }
        else {
            lr=m-1;
        }
        // cout << ll << " " << lr << " " << m << endl;
    }

    while(rl < rr) {
        int m=(rr+rl)/2;
        int md=m;
        bool v=false;
        for(int i=0; i<q; i++){
            if (t[i]!=s[md]) continue;

            if (d[i]=='L') md--;
            if (d[i]=='R') md++;
            if (md==-1 || md>=n) {
                v=(md>=n);
                break;
            }
        }
        if (v){
            rr=m;
        }
        else {
            rl=m+1;
        }
        // cout << rl << " " << rr << " " << m << endl;
    }

    cout << rl - ll - 1<< endl;

    return 0;
}