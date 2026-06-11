#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
void Main(){
    int n,ans = 0;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<int> vec(n,0);
    For(i,0,n-1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    priority_queue<int> pque;
    queue<int> que;
    For(i,0,n){
        int c;
        cin >> c;
        pque.push(c);
    }
    int nax = max_element(ALL(tree),[](auto l,auto r){
        return l.size() > r.size();
    }) - tree.begin();

    que.push(nax);
    vec[nax] = pque.top();
    pque.pop();

    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(auto to:tree[now]){
            if(vec[to] > 0) continue;
            que.push(to);
            vec[to] = pque.top();
            pque.pop();
            ans += vec[to];
        }
    }
    cout << ans << endl;
    For(i,0,n) cout << vec[i] << " ";
    cout << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}