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
#include <cmath>
#include <math.h> // sqrt()
#include <iomanip>
#define rep(i , n) for (int i = 1; i <= (int)(n); i++)
#define repz(i , n) for (int i = 0; i < (int) n; i++)
#define repi(i , r, n) for (int i = r; i <= (int)(n); i++)
#define repd(i , r, n) for (int i = r; i >= (int)(n); i--)


using namespace std;


int main(){
    int n , m , p;
    int64_t y;
    cin >> n >> m;
    vector< vector<int64_t >> kentoyear(n + 1);
    vector<vector<int64_t>> pair( m + 1);
    rep( i , m){
        cin >> p;
        pair[i].push_back(p);
        cin >> y;
        pair[i].push_back(y);
        kentoyear[p].push_back(y);
    }
    rep(i , n) {
        if ( kentoyear[i].size())
            sort(kentoyear[i].begin(), kentoyear[i].end());
    }
    rep( i , m){
        auto it = find(kentoyear[pair[i][0]].begin(), kentoyear[pair[i][0]].end(), pair[i][1]);
        int index = int(distance(kentoyear[pair[i][0]].begin(), it));
        printf("%06d" , int(pair[i][0]));
        printf("%06d\n" , index + 1);
    }
}
