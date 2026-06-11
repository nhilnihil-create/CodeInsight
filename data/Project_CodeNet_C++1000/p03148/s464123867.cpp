#include<bits/stdc++.h>
using namespace std;
const long long inf=1ll<<40;
// from http://drken1215.hatenablog.com/entry/2019/05/15/002400
int main(){
    long long  n,k;
    scanf("%lld %lld",&n,&k);
    vector<vector<long long>> s(n);
    for (int i=0;i<n;++i) {
        long long t,d;
        scanf("%lld %lld",&t,&d);
        t--;
        s[t].push_back(d);
    }
    for (auto &v : s) {
        sort(v.begin(),v.end(),greater<long long>());
        if (v.empty()) v.push_back(-inf);
    }
    sort(s.begin(),s.end(), [&](vector<long long> a, vector<long long> b){ return a[0]>b[0];});
    long long cur=0;
    priority_queue<long long> que;
    for (int i=0;i<k;i++) {
        cur+=s[i][0];
        for (int j=1;j<s[i].size();++j) que.push(s[i][j]);
    }

    for (int i=k;i<n;++i) for (int j=0;j<s[i].size();++j) {
        que.push(s[i][j]);
    }
    long long res=cur+k*k;
    for (long long x=k-1;x>=1;--x) {
        long long v=s[x][0];
        long long w=que.top();
        if (v<w) {
            que.pop();
            cur+=w;
            que.push(v);
            cur-=v;
        }
        res=max(res,cur+x*x);
    }

    printf("%lld\n",res);
    return 0;
}
