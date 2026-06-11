#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


int n;
vector<int> s;
vector<int> a;

int dfs(int k){
    if(k==n){
        int ret = 24;
        auto t = s;
        sort(ALL(t));
        for (int i = 0; i < n; i++) {
            int r = abs(t[(i+1)%n] - t[i]);
            ret = min(ret, min(24 - r, r));
        }
        return ret;
    }
    int ret = 0;
    if(a[k]==0||a[k]==12){
        s[k] = a[k];
        ret = max(ret, dfs(k+1));
    }
    else{
        s[k] = a[k];
        ret = max(ret, dfs(k+1));
        s[k] = 24 - a[k];
        ret = max(ret, dfs(k+1));
    }
    return ret;
}

 

int main(){
    cin >> n;
    a.resize(n+1);
    s.resize(n+1);
    a[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i+1];
    }
    n++;
    if(n>24){
        puts("0");
        return 0;
    }
    cout << dfs(0) << endl;
    return 0;
}
