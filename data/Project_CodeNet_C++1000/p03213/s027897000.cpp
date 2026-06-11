#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#define rep(i,m,n) for(int i=m; i<(n); i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
typedef long long ll;
using namespace std;

bool is_prime(const unsigned n)
{
    switch(n) {
        case 0:
        case 1: return false;
        case 2: return true;
    }

    if(n % 2 == 0) return false;
    for(unsigned i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> prime;
    rep(i,2,100)
    {
        if(is_prime(i)) prime.push_back(i);
    }
    int n;
    cin >> n;
    vector<int> ans(n+1);
    rep(i,0,n+1) ans[i] = 0;
    rep(i,0,prime.size())
    {
        bool ok = true;
        int beki = 1;
        while(ok)
        {
            int tmp = pow(prime[i],beki);
            if(tmp > n) ok = false;
            ans[prime[i]] += n/tmp;
            beki++;
        }
    }
    int sum = 0;
    int c1=0, c2=0;
    rep(i,1,n+1)
    {
        if(ans[i]>=4) c1++;
        if(ans[i]>=2) c2++;
    }
    sum += c1*(c1-1)/2*(c2 - 2);
    c1=0; c2=0;
    rep(i,1,n+1)
    {
        if(ans[i]>=14) c1++;
        if(ans[i]>=4) c2++;
    }
    sum += c1*(c2-1);
    c1=0;c2=0;
    rep(i,1,n+1)
    {
        if(ans[i]>=24) c1++;
        if(ans[i]>=2) c2++;
    }
    sum += c1*(c2-1);
    rep(i,1,n+1)
    {
        if(ans[i]>=74) sum++;
    }
    cout << sum << endl;
    return 0;
}
