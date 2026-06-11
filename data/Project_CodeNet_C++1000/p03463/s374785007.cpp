#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
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
#include <numeric>
#include <float.h>
#include <math.h>
using namespace std;
// repマクロの定義
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// allマクロの定義
#define all(v) v.begin(), v.end()

typedef unsigned long long ll;

int main(){
    int N,A,B; cin >> N >> A >> B;
    rep(i,100){
        if(i % 2 == 0 && B - A == 1){
            cout << "Borys"<< endl;
            break;
        }
        else if(i % 2 == 1 && B - A == 1){
            cout << "Alice" << endl;
            break;
        }
        if(i % 2 == 0){
            A++;
        }
        else{
            B--;
        }
    }
}