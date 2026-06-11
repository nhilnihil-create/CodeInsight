#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {
		if (ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*neg;
}
int vis[100005];
int n;
deque<pair<int,int> > q;
signed main() {
    n=read();
    q.push_front(make_pair(1,1));
    while(!q.empty()) {
        pair<int,int> p=q.front();
        q.pop_front();
        if(!vis[p.first]) {
            vis[p.first]=1;
            if(p.first==0) {
                printf("%lld\n",p.second);
                break;
            }
            q.push_front(make_pair((p.first*10)%n,p.second));
            q.push_back(make_pair((p.first+1)%n,p.second+1));
        }
    }
    return 0;
}