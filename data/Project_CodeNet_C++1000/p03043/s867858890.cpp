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

int n,k;

int kansu(int x){
    int count=0;
    while(x<k){
        x*=2;
        count++;
    }
return count;
}

int main(){
    cin>>n>>k;
    int i=1;
    vector<int>a(n,0);
    while(i<k&&i<=n){
       a[i-1]=kansu(i);
       i++;
    }
    double ans=0;
    rep(i,n)ans+=(double)(1/pow(2,a[i]));
    cout<<fixed<<setprecision(10)<<ans/n;
    return 0;
}