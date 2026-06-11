#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> a(n);
    rep(i,n-1){
        int ar,b,c;
        cin >> ar >> b >> c;
        ar--;
        b--;
        c%=2;
        a.at(ar).push_back(make_pair(b,c));
        a.at(b).push_back(make_pair(ar,c));
    }
    queue<int> q;
    vector<int> ans(n,-1);
    q.push(0);
    ans.at(0)=0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(auto i:a.at(k)){
            if(ans.at(i.first)!=-1)continue;
            ans.at(i.first)=i.second^ans.at(k);
            q.push(i.first);
        }
    }
    rep(i,n)
        cout << ans.at(i) << endl;
}