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
#include <iomanip> // fixed, setprecision 
#include <math.h> // double sqrt
#define rep(i,n) for(int i=0;i<(n);++i)
#define ll long long
using namespace std;

int f(int n){
    if(n%2==0)return n/2;
    else return 3*n+1;
}

int main(){
    vector<int>a(100000005);
    set<int>s;
    int i=0;
    cin>>a[0];
    s.insert(a[0]);
    while(1){
        a[i+1]=f(a[i]);
        if(s.count(a[i+1])){cout<<i+2;return 0;}
        s.insert(a[i+1]);
        i++;
    }
}