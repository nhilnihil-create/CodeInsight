#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


int n;
int a[maxn];

const int N = 1e5 + 10;
int bit[maxn];

void add(int i, int dx) {
    i += N;
    for (; i<=2*N; i+=i&-i) {
	bit[i] += dx;
    }
}

int qry(int i) {
    i += N;
    int res = 0;
    for (; i; i-=i&-i) {
	res += bit[i];
    }

    return res;
}


// True if (median of the subarrays) >= median
bool test(int median) {
    for (int i=0; i<=2*(N+2); i++) {
	bit[i] = 0;
    }


    
    int acc=0;
    add(acc, 1);
    
    ll cnt = 0;
    for (int i=1; i<=n; i++) {
	acc += (a[i]>=median ? +1 : -1);
	cnt += qry(acc);
	add(acc, 1);
    }

    //cout<<median<<": "<<cnt<<endl;
    
    ll len = 1ll*n*(n+1)/2;
    return cnt >= (len+1)/2;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++) {
	cin>>a[i];
    }

    int lo = 1;
    int hi = 1e9 + 1;
    while (hi-lo>1) {
	int mid = (lo+hi)/2;
	if (test(mid)) {
	    lo=mid;
	} else {
	    hi=mid;
	}
    }

    cout<<lo<<endl;
    return 0;
}
