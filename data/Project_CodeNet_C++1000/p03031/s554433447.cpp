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
    int n,m;
    cin>>n>>m;
    vector<int>k(m);
    vector< vector<int> > s(m, vector<int>(10));
    vector<int>a(n);
    vector<int>p(m);
    rep(i,m){
        cin>>k[i];
        rep(j,k[i])cin>>s[i][j];
    }
rep(i,m)cin>>p[i];
int ans=0;

for(int bit=0;bit<(1<<n);++bit){
    for(int i=0;i<n;i++){
        if(bit&(1<<i)){
            a[i]=1;
        }
    }
bool x=true;
rep(i,m){
    int count=0;
    rep(j,k[i]){
        if(a[s[i][j]-1]==1)count++;
    }
if(count%2!=p[i]){x=false;break;}
}
if(x==true)ans++;
rep(i,n)a[i]=0;
}

cout<<ans;
return 0;

}
