#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  Binary Indexed Tree
class BIT
{
    int n;
    vector<long long> v;
public:
    BIT(int n_) {
        n = 1;
        while (n < n_)
            n <<= 1;
        v = vector<long long>(n);
    }
    //  a[i] += x
    void add(int i, long long x) {
        for (; i<n; i|=i+1)
            v[i] += x;
    }
    //  return a[0]+a[1]+…+a[i-1]
    long long sum(int i) {
        long long s = 0;
        for (i--; i>=0; i=(i&(i+1))-1)
            s += v[i];
        return s;
    }
};

int main()
{
    int N;
    long long X;
    cin>>N>>X;
    vector<unsigned long long> x(N);
    for (unsigned long long &t: x)
        cin>>t;

    BIT bit(N);
    for (int i=0; i<N; i++)
        bit.add(i, x[i]);

    long long ans = 0x7fffffffffffffffLL;
    for (int k=1; k<=N; k++)
    {
        long long a = (N + k)*X;
        bool ok = true;
        for (int i=0; N-i*k>=0; i++)
        {
            long long s;
            if (N-i*k-k >= 0)
                s = bit.sum(N-i*k) - bit.sum(N-i*k-k);
            else
                s = bit.sum(N-i*k);
            a += (i==0 ? 5 : i*2+3) * s;
            if (a < 0)
                ok = false;
        }
        if (ok)
            ans = min(ans, a);
    }
    cout<<ans<<endl;
}
