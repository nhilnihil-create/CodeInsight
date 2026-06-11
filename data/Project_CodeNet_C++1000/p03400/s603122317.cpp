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
    int n,d,x;

    int f(int n){
        int count=0;
        int i=0;
        while(1){
            if(n*i+1>d)return count;
            count++;
            i++;
        }
    }
int main(){
    cin>>n>>d>>x;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int count=0;
    rep(i,n){
        count+=f(a[i]);
    }
    cout<<count+x;
    return 0;
}