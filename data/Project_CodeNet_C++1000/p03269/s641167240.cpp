#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <deque>
#define MOD 1000000007
#define REP(i,num)for(int i=0;i<(num);++i)
#define ll long long
using namespace std;

struct Edge {
    int x,y,v;
};

int main() {
    ios::sync_with_stdio(false);
    int L,x=2,v=1,longV=0,n;
    cin>>L;
    vector<Edge> edges;
    while (L>=(1<<(x-1))) {
        Edge e1,e2;
        e1.x=x-1;e1.y=x;e1.v=0;
        e2.x=x-1;e2.y=x;e2.v=(1<<(x-2));
        edges.push_back(e1);
        edges.push_back(e2);
        x++;
    }
    longV=(1<<(x-2));
    n=--x;
    if (L!=(1<<(x-1))) {
        L-=(1<<(x-1));
        x=n;
        while (L>0) {
            --x;
            if(L>=(1<<(x-1))){
                L-=(1<<(x-1));
                Edge e;
                e.x=x;e.y=n;e.v=longV;
                edges.push_back(e);
                longV+=(1<<(x-1));
            }
        }
    }
    
    cout<<n<<" "<<edges.size()<<endl;
    for(auto edge: edges){
        cout<<edge.x<<" "<<edge.y<<" "<<edge.v<<endl;
    }
    return 0;
}
