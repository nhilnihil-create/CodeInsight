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

    int n; cin >> n;
    int ans = 0;
    int counta = 0, countb = 0;

    int hantei = 1;
    vector<int> ora(n),orb(n);

    for(int i = 0;i < n;i ++){
        string s; cin >> s;

        for(int j = 0;j < s.size()-1;j ++){
            if(s.at(j) == 'A' && s.at(j+1) == 'B') ans ++;
        }

        if(s.at(0) == 'B'){
            countb ++;
            orb.at(i) = 1;
        }
        if(s.at(s.size()-1) == 'A'){
            counta ++;
            ora.at(i) = 1;
        }
    }

    for(int i = 0;i < n;i ++){
        if(ora.at(i) - orb.at(i) != 0) hantei = 0;
    }

    bool all0 = true;
    for(int i = 0;i < n;i ++){
        if(ora.at(i) == 1 || orb.at(i) == 1) all0 = false;
    }

    if(all0 == true) hantei = 0;

    int ab = min(counta,countb);

    cout << ans + min(ab, n) - hantei << endl;

}