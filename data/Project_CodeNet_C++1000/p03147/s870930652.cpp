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

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    int ans=0;
    while(1){
        int i=0;
        int M=0;
        while(1){
            bool f=false;
            while(h[i]!=0 && i<n){
                h[i]--;
                M=max(M,h[i]);
                i++;
                f=true;
            }
            while(h[i]==0 && i<n){
                i++;
            }
            if(f) ans++;
            if(i==n) break;
        }
        if(M==0) break;
    }
    cout<<ans<<endl;
}