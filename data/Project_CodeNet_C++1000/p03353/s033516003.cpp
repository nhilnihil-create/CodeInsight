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
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;


int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    set<string> ss;
    int n=s.length();
    for(int i=0;i<n;i++){
        string buf;
        for(int l=0;l<5;l++){
            if(i+l>=n) break;
            buf+=s[i+l];
            ss.insert(buf);
        }
    }
    auto itr=ss.begin();
    for(int i=0;i<k-1;i++){
        itr++;
    }
    cout<<*itr<<endl;
}