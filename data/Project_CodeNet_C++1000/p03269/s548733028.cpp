#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define PI acos(-1.0)
const int N=1e5 + 5;
const int M=1e5 + 5;
 
vector < pair < int , ll > > g[N];

ll fun(vector <int> v, int id)
{
    ll res = 0;
    for(int i=0;i<v.size();i++){
        if(i>id){
            if(v[i]) res+=(1LL<<i);
        }

    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    ll l;
    cin>>l;
    vector <int> v;
    while(l>0){
        if(l%2) v.pb(1);
        else v.pb(0);
        l/=2;
    } 
    int m=0;
    int n = v.size();
    int i;
    for(i=1;i<n;i++){
        g[i].pb(mkp(i+1,(1LL<<(i-1))));
        g[i].pb(mkp(i+1,0));
        m+=2;
    }
    for(i=0;i<n-1;i++){
        if(v[i]){
            ll foo = fun(v,i);
            g[i+1].pb(mkp(n,foo));
            m++;
        }
    }
    cout << n << " " << m << endl;
    for(i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            cout << i << " "<<g[i][j].fi << " "<<g[i][j].se << endl;
        }
    }

 
    return 0;
}