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
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>p(n);
    rep(i,n)cin>>p[i];
    int x=0,y=0,z=0;
    rep(i,n){
        if(p[i]<=a)x++;
        else if(p[i]>=a+1&&p[i]<=b)y++;
        if(p[i]>=b+1) z++;
    }
cout<<min(min(x,y),z);
}
