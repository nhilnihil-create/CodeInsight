#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using ll=long long;  
using pLL = std::pair<ll, ll>;
ll N,P;

#define SORT(v) std::sort(v.begin(), v.end())
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >>P;
  
    if(P==1){
        cout << 1 << endl;
        return 0;
    }else if(N==1){
        cout << P <<endl;
        return 0;
    }
    map<int,int> mp;
    int j=2;
    while(P%j==0){
        P/=j;
        mp[2]++;
        
    }
    for(ll j=3;j*j<=P;j+=2){
        while(P%j==0){
            P/=j;
            mp[j]++;
            
        }
    }
    int ans=1;
    for(auto i=mp.begin();i!=mp.end();++i){
        if(i->second>=N){
            for(int j=0;j<(i->second/N);j++)
            ans*=i->first;
        }
    }
    cout << ans <<endl;
    return 0;
}