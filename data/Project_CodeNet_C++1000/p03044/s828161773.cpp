#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007

struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};

using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<edge>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;


int main(){

    int n; cin >> n;
    Graph G(n);
    rep(i,n-1){
        int a,b,w; cin >> a >> b >> w;
        a--;b--;
        G.at(a).push_back(edge(b,w));
        G.at(b).push_back(edge(a,w));
    }

    vector<int> ans(n,-1);
    queue<edge> q;
    ans.at(0) = 0;
    q.push(edge(0,0));
    while(!q.empty()){
        edge v = q.front();
        q.pop();
        for(auto nv : G.at(v.to)){
            if(ans.at(nv.to) != -1) continue;
            ans.at(nv.to) = (ans.at(v.to)+nv.weight)%2;
            q.push(nv);
        }
    }
    rep(i,n) cout << ans.at(i) << endl;

    return 0;
}
