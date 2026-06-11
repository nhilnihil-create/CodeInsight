//#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

int n;
vector<int> to[100005];
int dis[100005];

int ans[100005];
int ch[100005];

int main(){
    int m;
    cin >> n>>m;
    /*
    set<int> S;
    rep(i,n){
        S.insert(i);
    }
    */
    
    //最長路問題
    //int a[n+m-1],b[n+m-1];
    rep(i,n+m-1){
        int a,b;
        cin >> a>> b;
        a--;b--;
        to[a].push_back(b);
        //S.erase(b[i]);
        ch[b]++;
    }
    //int s=*S.begin();
    int s=-1;
    rep(i,n){
        if(ch[i]==0)s=i;
    }
    pq.push(s);
    while(!pq.empty()){
        int p=pq.top();
        pq.pop();
        for(int u:to[p]){
            if(--ch[u]==0){
                dis[u]=dis[p]+1;
                ans[u]=p+1;
                pq.push(u);
            }
        }
    }
    //cerr<<endl;
    rep(i,n){
        cout<<ans[i]<<endl;
    }
    return 0;
}

