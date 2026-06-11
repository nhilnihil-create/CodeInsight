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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int main(){
    int n;cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;++i) cin>>s[i];
    int ans=0;
    for(int a=0;a<n;++a){
        bool ok=true;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(s[(i+a)%n][j]!=s[(j+a)%n][i]) ok=false;
            }
        }
        if(ok) ans+=(n-a);
    }
    for(int b=1;b<n;++b){
        bool ok=true;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(s[i][(j+b)%n]!=s[j][(i+b)%n]) ok=false;
            }
        }
        if(ok) ans+=(n-b);
    }
    cout<<ans<<endl;
    return 0;
}