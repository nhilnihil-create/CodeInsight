#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = (1<<18);

int A[N];
int dp[N];

set<pair<int,int> >ret[N];

void solve() {
    int n;
    scanf("%d",&n);
    int lim = (1<<n);
    for(int i=0;i<lim;++i) {
        scanf("%d",&A[i]);
    }
    ret[0].insert(make_pair(A[0],0));
    int prev = 0;
    set<pair<int,int> >::iterator it;
    for(int bit=1;bit<lim;++bit) {
        for(int i=0;i<n;++i) {
            if(bit&(1<<i)){
                int x = bit^(1<<i);
                for(it  = ret[x].begin();it!= ret[x].end();++it) {
                    ret[bit].insert(*it);
                }
                while(ret[bit].size()>2) {
                    ret[bit].erase(ret[bit].begin());
                }
            }
        }
        ret[bit].insert(make_pair(A[bit],bit));
        if(ret[bit].size()>2) {
            ret[bit].erase(ret[bit].begin());
        }
        
        if(ret[bit].size()==2) {
            int x = 0;
            for(it = ret[bit].begin();it!= ret[bit].end();++it) {
                x += (*it).first;
            }
            prev = max(prev,x);
        }
        printf("%d\n", prev);
    }
}

int main() {
   //freopen("input.txt","r",stdin);
   solve();
}
