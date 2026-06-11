#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999999;



int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n),d(n);
    map<int,vector<int> > red;
    map<int,vector<int> > blue;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        red[a[i]].push_back(b[i]);
    }

    for(int i=0;i<n;i++){
        cin>>c[i]>>d[i];
        blue[c[i]].push_back(d[i]);
    }

    vector<int> rys(0);;

    int ans=0;
    for(int i=0;i<2*n;i++){
        if(blue[i].size()){
            int by=blue[i][0];
            if(rys.size()==0) continue;
            sort(rys.begin(),rys.end());
            int itr=lower_bound(rys.begin(), rys.end(), by) - rys.begin();
            if(itr==0) continue;
            rys.erase(lower_bound(rys.begin(), rys.end(), by)-1);
            ans++;
        }
        if(red[i].size()){
            rys.push_back(red[i][0]);
        }
    }
    cout<<ans<<endl;


}