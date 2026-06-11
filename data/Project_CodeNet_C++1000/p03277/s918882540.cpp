#include <bits/stdc++.h>
using namespace std;

template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;
    
    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }
    
    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int ok=1000000000,ng=0;
	while (ok-ng>1)
	{
		int mid=(ok+ng)/2;
		long long now=0LL;
		BIT<long long> bit(2*n+5);
		int s=0;
		bit.add(n+1,1LL);
		for (int i = 0; i < n; ++i)
		{
			int tmp=1;
			if (a[i]>mid)
			{
				tmp=-1;
			}
			s+=tmp;
			now+=bit.sum(1,s+n+1);
			bit.add(s+n+1,1LL);
		}
		if (now>(long long)(n+1LL)*n/4LL)
		{
			ok=mid;
		}
		else
		{
			ng=mid;
		}
	}
	cout<<ok<<endl;
	return 0;
}
