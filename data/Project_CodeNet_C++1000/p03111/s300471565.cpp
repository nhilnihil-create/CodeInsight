#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;

int n,a,b,c;
vector<int> l;
vector<int> s;
vector<int> m;

void dfs(int i,int sum1, int sum2, int sum3,int merge1,int merge2, int merge3){
    if(i==n){
        if(merge1==0 || merge2==0 || merge3==0) return;
        int dis = abs(sum1-a)+abs(sum2-b)+abs(sum3-c);
        s.push_back(dis);
        int tot = merge1 + merge2 + merge3;
        if(merge1!=0) tot--; 
        if(merge2!=0) tot--; 
        if(merge3!=0) tot--; 
        m.push_back(tot);
        return;
    }
    dfs(i+1,sum1,sum2,sum3,merge1,merge2,merge3);
    dfs(i+1,sum1+l[i],sum2,sum3,merge1+1,merge2,merge3);
    dfs(i+1,sum1,sum2+l[i],sum3,merge1,merge2+1,merge3);
    dfs(i+1,sum1,sum2,sum3+l[i],merge1,merge2,merge3+1);
}

int main(){
    cin >> n >> a >> b >> c;
    rep(i,n) {
        int tmp;
        cin >> tmp;
        l.push_back(tmp);
    }
    dfs(0,0,0,0,0,0,0);
    int ans = 1e9;
    rep(i,(int)s.size()){
        int now;
        now = s[i] + m[i]*10;
        ans = min(now,ans);
    }
    cout << ans << endl;
    return 0;
}