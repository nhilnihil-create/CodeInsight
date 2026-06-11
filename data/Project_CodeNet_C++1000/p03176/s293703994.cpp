#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
 

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
#include <functional>

using namespace std;

class SegmentTree
{
private:
    int n;
    vector<ll> node;

    void init_size(int sz)
    {
        this->n = 1;
        while(n < sz){
            this->n *= 2;
        }
        this->node = vector<ll>(2 * this->n - 1, 0);
    }

public:
    SegmentTree(int n)
    {
        init_size(n);
    }

    SegmentTree(vector<int> v) {

        int size = v.size();
        init_size(size);

        for(int i=0;i<size;++i)
        {
            node[i+n-1] = v[i];
        }

        for(int i=n-1;i>=0;i--)
        {
            node[i] = max(node[2*i+1], node[2*i+2]);
        }
    }

    void update(int pos, ll val)
    {
        pos += (n - 1);
        node[pos] = val;
        while(pos > 0)
        {
            pos = (pos - 1) / 2;
            node[pos] = max(node[2*pos+1], node[2*pos+2]);
        }
    }

    ll get(int begin, int end, int current=0, int l=0, int r=-1)
    {
        if(r < 0) r = this->n;
        if(r <= begin || end <= l) return 0; // initial value
        if(begin <= l && r <= end) return node[current];

        ll val_left = get(begin, end, 2*current+1, l, (l+r)/2);
        ll val_right = get(begin, end, 2*current+2, (l+r)/2, r);
        return max(val_left, val_right);
    }

    void print()
    {
      for(int i=0;i<n;++i)
      {
        cerr << node[i+(n-1)] << ",\n"[i==n-1];
      }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int h[n] = {};
    ll a[n] = {};

    SegmentTree segtree(n);

    for(int i=0;i<n;++i)
    {
      cin >> h[i];
    }

    for(int i=0;i<n;++i)
    {
      cin >> a[i];
    }

    for(int i=0;i<n;++i)
    {
      int height = h[i];
      ll tmp_max = segtree.get(0, height);
      segtree.update(height-1, tmp_max + a[i]);
      //segtree.print();
    }

    cout << segtree.get(0, n) << endl;
}