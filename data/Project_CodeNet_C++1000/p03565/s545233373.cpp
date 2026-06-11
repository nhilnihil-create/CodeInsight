#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string s,t; cin >> s >> t;
    int n = s.size();
    int m = t.size();

    if(n < m){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for(int i = 0;i < n-m+1;i ++){
        if(s.substr(i,m) == t){
            for(int j = 0;j < n;j ++){
                if(s.at(j) == '?') s.at(j) = 'a';
            }
            cout << s << endl;
            return 0;
        }
    }

    for(int i = n-m;i >= 0;i --){
        int hantei = 1;
        for(int j = 0;j < m;j ++){
            if(!(s.at(i+j) == '?' || s.at(i+j) == t.at(j))){
                hantei = 0;
                break;
            }
        }

        if(hantei == 1){
            for(int j = 0;j < m;j ++){
                s.at(i+j) = t.at(j);
            }
            break;
        }

        if(i == 0 && hantei == 0){
            cout << "UNRESTORABLE" << endl;
            return 0;
        }
    }

    for(int i = 0;i < n;i ++){
        if(s.at(i) == '?') s.at(i) = 'a';
    }

    cout << s << endl;
}