#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n,a,b;
int mn,mx;
int cnt[maxn];
deque<int> res, t;
int main() {
    int cur;
    scanf("%d%d%d",&n,&a,&b);
    mn = min(a,b); mx = max(a,b);
    cnt[0] = mn;
    for(int i=mn+1,pos=0;i<=n;i++) {
        if(pos==0) pos = (pos+1)%mx;
        cnt[pos]++;
        pos = (pos+1)%mx;
    }
    for(int i=0,cur=0;i<mx;i++) {
        if(cnt[i]==0 || cnt[i]>mn) return !printf("-1");
        t.clear();
        while(cnt[i]--) t.push_front(++cur);
        for(auto x : t) res.push_back(x);
    }
    if(a<b) reverse(res.begin(),res.end());
    for(auto x : res) printf("%d ",x);
}
