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
    string s, t;
    cin >> s >> t;
    map<char , char> dict;
    map<char , char> dicttwo;
    bool one = true; bool two = true;
    repz( i , s.size()){
        if (not(dict[s.at(i)])) dict[s.at(i)] = t.at(i);
        else{
            if(dict[s.at(i)] != t.at(i)) one = false;
        }
        if (not(dicttwo[t.at(i)])) dicttwo[t.at(i)] = s.at(i);
        else{
            if(dicttwo[t.at(i)] != s.at(i)) two = false;
        }
    }
    if ( one & two) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
}
