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
    vector<int> d(n),c(13,0);
    for(int i=0;i<n;++i){
        cin>>d[i];
        c[d[i]]++;
    }
    for(int i=0;i<=12;++i){
        if(c[i]>=3){
            cout<<0<<endl;
            return 0;
        }
    }
    vector<int> t;
    int sw=0;
    for(int i=0;i<=12;++i){
        if(c[i]==2){
            t.push_back(i);
            t.push_back(24-i);
        }else if(c[i]==1){
            if(sw==1){
                t.push_back(24-i);
            }else t.push_back(i);
            sw=1-sw;
        }
    }
    t.push_back(0);
    sort(t.begin(),t.end());
    int ans=24;
    for(int i=0;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ans=min(ans,min(t[j]-t[i],24-(t[j]-t[i])));
        }
    }
    cout<<ans<<endl;
    return 0;
}