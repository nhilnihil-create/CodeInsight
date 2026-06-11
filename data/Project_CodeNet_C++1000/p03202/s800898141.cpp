#include<bits/stdc++.h>
using namespace std;

int n, a[202000], ans;

stack<int>w, c, e;

bool ok(int aim){
    w=c=e;    
    for (int i=2;i<=n;++i){
        if (a[i]>a[i-1]) continue;
        while (w.size()&&w.top()>a[i]) w.pop(), c.pop();
        int p=a[i];
        while (w.size()&&w.top()==p&&c.top()==aim) w.pop(), c.pop(), --p;
        if (p==0) return 0;
        if (w.size()&&w.top()==p) c.top()++;
        else {
            if (aim==1) return 0;
            w.push(p), c.push(2);
        }
    }
    return 1;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    int l=1, r=n;
    while (l<=r){
        int mid=l+r>>1;
        if (ok(mid)) r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
}