#include <bits/stdc++.h>

#define PB emplace_back
#define mid ((be+en)/2)
#define cl c*2
#define cr cl+1

using namespace std;

const int N = (1e5+100)*16;

long long int mx[N], dp[N], h[N], a[N], n;

long long int que(int l, int r, int be=0, int en=n, int c=1) {
    if(r<=be||en<=l)return 0;
    if(l<=be&&en<=r)return mx[c];
    return max(que(l,r,be,mid,cl),que(l,r,mid,en,cr));
}

long long int up(int l, long long int val, int be=0, int en=n, int c=1) {
    if(be+1==en) mx[c]=val;
    else if(l<mid)up(l,val,be,mid,cl);
    else up(l,val,mid,en,cr);
    if(be+1!=en)mx[c]=max(mx[cl],mx[cr]);
}

int main () {
    cin >> n;
    for(int i = 0 ; i < n ; i++ ) cin >> h[i];
    for(int i = 0 ; i < n ; i++ ) cin >> a[i];
    for(int i = 0 ; i < n ; i++ ) {
        long long int xm = que(0,h[i]);
        up(h[i],xm+a[i]);
    }
    cout << que(0,*max_element(a,a+n)+1);
}
