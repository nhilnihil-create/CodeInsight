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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
map<char,ll> mp;
char l[5]={'M','A','R','C','H'};

int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        char a=s[0];
        mp[a]++;
    }
    ll ans=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                ans+=mp[l[i]]*mp[l[j]]*mp[l[k]];
            }
        }
    }
    cout<<ans<<endl;
}