//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1000 + 5;
const ll OO = 1e18;

int x,y,z,k;
ll a[N],b[N],c[N],sum;
map<tuple<int,int,int>, int> vis;
priority_queue<tuple<ll,int,int,int> > pq;

void init() {



}

int main() {

ios_base::sync_with_stdio(false);
cin.tie(0);

cin >> x >> y >> z >> k;

for(int i=0;i<x;++i) {

    cin >> a[i];

}

sort(a,a+x);

for(int i=0;i<y;++i) {

    cin >> b[i];

}

sort(b,b+y);

for(int i=0;i<z;++i) {

    cin >> c[i];

}

sort(c,c+z);

int curX = x-1, curY = y-1, curZ = z-1;
sum = a[curX]+b[curY]+c[curZ];
pq.emplace(sum,curX,curY,curZ);

while(k--) {

    tuple<ll,int,int,int> cur = pq.top();
    pq.pop();

    curX = get<1>(cur);
    curY = get<2>(cur);
    curZ = get<3>(cur);

    if(vis[make_tuple(curX,curY,curZ)]) {
        ++k;
        continue;
    }

    vis[make_tuple(get<1>(cur),get<2>(cur),get<3>(cur))] = 1;

    cout << get<0>(cur) << '\n';

    if(curX>0 && !vis[make_tuple(curX-1,curY,curZ)]) {

        pq.emplace(a[curX-1]+b[curY]+c[curZ],curX-1,curY,curZ);

    }

    if(curY>0 && !vis[make_tuple(curX,curY-1,curZ)]) {

        pq.emplace(a[curX]+b[curY-1]+c[curZ],curX,curY-1,curZ);

    }

    if(curZ>0 && !vis[make_tuple(curX,curY,curZ-1)]) {

        pq.emplace(a[curX]+b[curY]+c[curZ-1],curX,curY,curZ-1);

    }

}

return 0;

}