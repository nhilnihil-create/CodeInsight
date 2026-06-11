#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;

set<long long> s, t;

long long mn(long long x, int wh, int p){
    if(wh == -1){
        return min(mn(x, 1, -1), mn(x, 2, -1));
    }
    else if(wh == 1){
        auto k = s.lower_bound(x);
        if(k == s.end()){
            k--;
            long long l = x - *k;
            if(p == 2) return l;
            return l + mn(*k, 2, 1);
        }
        else if(k == s.begin()){
            long long r = *k - x;
            if(p == 2) return r;
            return r + mn(*k, 2, 1);
        }
        else{
            long long r = *k - x;
            auto k1 = k;
            k1--;
            long long l = x - *k1;
            if(p == 2) return min(l, r);
            return min(l + mn(*k1, 2, 1), r + mn(*k, 2, 1));
        }
    }
    else{
        auto k = t.lower_bound(x);
        if(k == t.end()){
            k--;
            long long l = x - *k;
            if(p == 1) return l;
            return l + mn(*k, 1, 2);
        }
        else if(k == t.begin()){
            long long r = *k - x;
            if(p == 1) return r;
            return r + mn(*k, 1, 2);
        }
        else{
            long long r = *k - x;
            auto k1 = k;
            k1--;
            long long l = x - *k1; 
            if(p == 1) return min(l, r);
            return min(l + mn(*k1, 1, 2), r + mn(*k, 1, 2));
        }
    }
}


int main(){
    long long a, b, q, x, s1, t1;
    cin >> a >> b >> q;
    for(int i = 0; i < a; ++i){
        cin >> s1;
        s.insert(s1);
    }
    for(int i = 0; i < b; ++i){
        cin >> t1;
        t.insert(t1);
    }
    for(int i = 0; i < q; ++i){
        cin >> x;
        cout << mn(x, -1, -1) << endl;

    }
}
