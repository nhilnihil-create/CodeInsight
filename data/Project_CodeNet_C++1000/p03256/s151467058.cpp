#include<bits/stdc++.h>
using namespace std;

char str[200005];
int cnt[200005][2];
bool ok[200005];
vector<int> g[200005];
set< pair<int, int> > already;
queue<int> q;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", str);
    for(int i=0;i<m;i++){
        int aa, bb;
        scanf("%d%d", &aa, &bb);
        aa--; bb--;
        if(already.find({aa, bb}) != already.end()) continue;
        if(already.find({bb, aa}) != already.end()) continue;
        g[aa].push_back(bb);
        g[bb].push_back(aa);
        cnt[aa][str[bb]-'A']++;
        cnt[bb][str[aa]-'A']++;
        already.insert({aa, bb});
        already.insert({bb, aa});
    }
    for(int i=0;i<n;i++){
        if(cnt[i][0] == 0 || cnt[i][1] == 0){
            ok[i] = false;
            q.push(i);
        }else{
            ok[i] = true;
        }
    }
    int lft = n;
    while(!q.empty()){
        int me = q.front(); q.pop();
        lft--;
        for(auto &nxt: g[me]){
            if(!ok[nxt]) continue;
            cnt[nxt][str[me]-'A']--;
            if(cnt[nxt][0] == 0 || cnt[nxt][1] == 0){
                ok[nxt] = false;
                q.push(nxt);
            }
        }
    }
    if(lft) printf("Yes\n");
    else printf("No\n");
}
