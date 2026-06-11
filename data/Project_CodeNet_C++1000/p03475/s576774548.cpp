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
    vector<int> c(n),s(n),f(n);
    for(int i=0;i<n-1;i++){
        cin>>c[i]>>s[i]>>f[i];
    }
    vector<int> ans(n);
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(ans[i]<=s[j]){
                ans[i]=s[j]+c[j];
            }else{
                int buf=ans[i];
                ans[i]=((ans[i]-s[j])/f[j]+1)*f[j]+s[j]+c[j];
                if((buf-s[j])%f[j]==0) ans[i]-=f[j];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}