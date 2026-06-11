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


using namespace std;

int main(){
    int n, m , c;
    cin >> n >> m >> c;
    int var[n+ 1][m + 1];
    int b[m + 1];
    for ( int i = 1 ; i <= m; i++)
        cin >> b[i];
    for ( int i = 1 ; i <= n; i++){
        for ( int j = 1; j <= m; j++)
            cin >> var[i][j];
    }
    int count = 0;
    for ( int i = 1 ; i <= n; i++){
        int s = 0;
        for ( int j = 1; j <= m; j++){
            s += b[j] * var[i][j];
        }
        if ( (s + c) > 0) count++;
        
    }
    cout << count << endl;
    
}