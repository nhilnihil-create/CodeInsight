//
// Created on 2020/07/29.
//


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
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n,q;
    string s;
    cin>>n>>q;
    cin>>s;
    vector<int>g(n,0);
    for (int i = 1; i < n ; ++i) {
        if(s[i - 1] == 'A' && s[i] == 'C'){
            g[i] = g[i - 1] + 1;
        }else{
            g[i]= g[i - 1];
        }
    }
    for (int k = 0; k < q; ++k) {
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout<<g[r] - g[l]<<endl;
    }

    return 0;
}
