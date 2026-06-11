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
    string s;
    cin>>s;
    int ans=0;
    for(int i=1;i<n-1;i++){
        map<char,int> mp;
        int cc=0;
        for(int j=0;j<i;j++){
            mp[s[j]]++;
        }
        for(int j=i;j<n;j++){
            if(mp[s[j]]>0){
                cc++;
                mp[s[j]]=0;
            }
        }
        ans=max(ans,cc);
    }
    cout<<ans<<endl;
}