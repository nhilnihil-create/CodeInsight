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
bool check(int64_t x){
    bool ok = false;
    int a = 0; int b = 0; int c = 0;
    for (char l : to_string(x)){
        if (l == '3') a++;
        else if( l == '5') b ++;
        else c++;
    }
    if ( a && b && c) ok = true;
    return ok;
}

int calc(int64_t x , int64_t n){
    int num[3] = {7 , 5 , 3};
    if ( x > n) return 0;
    int s = 0;
    if (check(x)) s = 1;
    else s = 0;
    for (int i : num) s+= calc( 10 * x + i , n);
    return s;
    
}

int main(){
   int64_t n;
    cin >> n;
    cout <<calc( 0 , n) << endl;
}
