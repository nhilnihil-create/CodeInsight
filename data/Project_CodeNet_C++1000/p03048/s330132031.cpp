#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int res=0;
    for(int i=0;i<=3030;i++){
        for(int j=0;j<=3030;j++){
            int k=n-r*i-g*j;
            if(0<=k&&k%b==0)res++;
        }
    }
    cout<<res<<endl;
}