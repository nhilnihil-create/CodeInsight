#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e5 + 10;

int n,a[maxn],t[2*maxn],res;

void update(int x) {
    while (x<2*maxn) {
        t[x]++;
        x += x&(-x);
    }
}

int Get(int x) {
    int res=0;
    while (x>0) {
        res += t[x];
        x -= x&(-x);
    }
    return res;
}

int main() {
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int> tmp;
    for (int i=1;i<=n;i++) tmp.push_back(a[i]);
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end()) - tmp.begin());
    int l = 0, r= tmp.size()-1;
    ll all = 1ll*n*(n+1)/2;
    while (l<=r) {
        int mid = (l+r)/2;
        int X = tmp[mid];
       // cout<<X<<" "<<l<<" "<<r<<endl;
        memset(t,0,sizeof(t));
        int cur = n+1;
        update(cur);
        ll num=0;
        for (int i=1;i<=n;i++) {
            if (a[i]<=X) cur++;
            else cur--;
            //cout<<Get(cur)<< " cur = " <<cur<< " ";
            num += Get(cur-1);
            update(cur);
        }
        //cout<<num<<endl;
        if (2*num <= all) l = mid+1;
        else res=mid,r = mid-1;

    }
    cout<<tmp[res]<<endl;
}
