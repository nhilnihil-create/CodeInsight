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
    int n,m;
    cin >> n >> m;
    vector<long long> x(n);
    vector<long long> y(n);
    vector<long long> z(n);
    vector<long long> sum1(n);
    vector<long long> sum2(n);
    vector<long long> sum3(n);
    vector<long long> sum4(n);
    vector<long long> sum5(n);
    vector<long long> sum6(n);
    vector<long long> sum7(n);
    vector<long long> sum8(n);
    vector<long long> a(8,0);
    for(int i=0; i<n; i++){
      cin >> x[i] >> y[i] >> z[i];
      sum1[i]=x[i]+y[i]+z[i];
      sum2[i]=x[i]-y[i]+z[i];
      sum3[i]=x[i]+y[i]-z[i];
      sum4[i]=x[i]-y[i]-z[i];
      sum5[i]=-x[i]+y[i]+z[i];
      sum6[i]=-x[i]-y[i]+z[i];
      sum7[i]=-x[i]+y[i]-z[i];
      sum8[i]=-x[i]-y[i]-z[i];
    }
    sort(sum1.begin(),sum1.end());
    sort(sum2.begin(),sum2.end());
    sort(sum3.begin(),sum3.end());
    sort(sum4.begin(),sum4.end());
    sort(sum5.begin(),sum5.end());
    sort(sum6.begin(),sum6.end());
    sort(sum7.begin(),sum7.end());
    sort(sum8.begin(),sum8.end());
    for(int i=0; i<m; i++){
        a[1]+=sum1[n-1-i];
        a[2]+=sum2[n-1-i];
        a[3]+=sum3[n-1-i];
        a[4]+=sum4[n-1-i];
        a[5]+=sum5[n-1-i];
        a[6]+=sum6[n-1-i];
        a[7]+=sum7[n-1-i];
        a[0]+=sum8[n-1-i];
    }
    sort(a.begin(),a.end());
    cout << a[7] << endl;

}
