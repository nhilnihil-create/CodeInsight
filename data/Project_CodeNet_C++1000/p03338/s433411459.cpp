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
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i,N) for(int i=0;i<(int)N;++i)

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

bool my_compare(pair<string, int> a, pair<string, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return true;
    }
}

int main()
{
    int N;
    string S,X,Y;
    cin>>N;
    cin>>S;

    deque<int> deq;

for(int i=1;i<=N-1;++i){
X=S.substr(0,i);
Y=S.substr(i,N-i);

sort(X.begin(),X.end());
sort(Y.begin(),Y.end());

X.erase(unique(X.begin(),X.end()),X.end());
Y.erase(unique(Y.begin(),Y.end()),Y.end());

int m=X.size(), n=Y.size();

int jj=0;
for(int p=0;p<m;++p){
for(int q=0;q<n;++q){
if(X[p]==Y[q]){++jj;}
}
}

deq.push_back(jj);

}

int M=0;

int t=deq.size();

for(int i=0;i<t;++i){
M=max(M,deq[i]);
}

cout<<M<<endl;

}