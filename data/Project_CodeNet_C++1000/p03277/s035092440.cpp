#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;


template<class T> class BIT   // 1-indexed (0 is not used)
{
private:
    int num;
    vector<T> bit;
public:
    BIT(int n):bit(vector<T>(n+1, 0)), num(n) {}

    T sum(int i) {   // sum of 1..i
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, T x) {
        if (i > num) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }

    int lower_bound(T x) {
        T res=0;
        int N=1;
        while(N<num) N*=2;
        int i;
        for(i=N/2; i>0; i/=2) {
            if(res+i<num && bit[res+i]<x) {
                x = x - bit[res +i];
                res = res + i;
            }
        }
        return res + 1;
    }
};

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    set<int> z;
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        z.insert(a[i]);
    }
    vector<int> b;
    copy(z.begin(), z.end(), back_inserter(b));
    int siz=(int)b.size();

    int l=-1,r=siz;
    while(r-l>1) {
        int m=(l+r)/2;
        vector<int> aa(n),saa(n+1);
        for(i=0; i<n; i++) {
            if(a[i]<b[m]) aa[i]=1;
            else aa[i]=-1;
            saa[i+1]=saa[i]+aa[i];
        }

        ll sum=0;
        int num=n+10;
        BIT<int> bit(num*2);
        for(i=0; i<n+1; i++) {
            sum+=bit.sum(saa[i]+num-1);
            bit.add(saa[i]+num, 1);
        }
        if(sum>(ll)n*(n+1)/4) {
            r=m;
        }
        else {
            l=m;
        }
    }
    printf("%d\n", b[l]);

    return 0;
}

