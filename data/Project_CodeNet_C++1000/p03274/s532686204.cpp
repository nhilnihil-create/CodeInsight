#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // long long64_t, long long*_t
#include <cstdio> // prlong longf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
using namespace std;
int main(){
    int n,k;
    long long ans;
    cin >> n >> k;
    vector<long long> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    ans=abs(x[k-1]-x[0])+abs(x[0]);
    for(int i=0; i<n-k+1; i++){
      long long a;
      a=min(abs(x[k-1+i]-x[i])+abs(x[i]),abs(x[k-1+i]-x[i])+abs(x[k-1+i]));
      ans=min(ans,a);
    }
    cout << ans << endl;
}
