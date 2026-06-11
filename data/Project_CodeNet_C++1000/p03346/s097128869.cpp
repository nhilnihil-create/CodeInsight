#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, int> P;
typedef long long ll;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXV = 10000;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int main(){
    int n;cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;++i){
        cin>>p[i];p[i]--;
    }
    vector<int> q(n);
    for(int i=0;i<n;++i){
        q[p[i]]=i;
    }
    int ans=0;
    int right=0;
    for(int left=0;left<n;++left){
        while(right<n-1&&q[right]<q[right+1]) right++;
        ans=max(ans,right-left+1);
        if(right==left) right++;
    }
    ans=n-ans;
    cout<<ans<<endl;
    return 0;
}