#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;


int main(){

    int n; cin >> n;
    Graph to(n),co(n);
    rep(i,n-1){
        int a,b,w; cin >> a >> b >> w;
        a--;b--;
        to.at(a).push_back(b);
        to.at(b).push_back(a);
        co.at(a).push_back(w);
        co.at(b).push_back(w);
    }

    vector<int> ans(n,-1);
    queue<int> q;
    ans.at(0) = 0;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        rep(i,to.at(v).size()){
            int u = to.at(v).at(i);
            int w = co.at(v).at(i);
            if(ans.at(u) != -1) continue;
            ans.at(u) = (ans.at(v)+w)%2;
            q.push(u);
        }
    }
    rep(i,n) cout << ans.at(i) << endl;

    return 0;
}
