#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin >> h >> w;
    bool c[h*w]={};
    int dist[h*w];
    int cnt=0;
    for(int i = 0; i < h; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < w; j++) {
            if(tmp[j]=='.'){
                c[i*w+j]=true;
                dist[i*w+j]=-1;
                cnt++;
            }
        }
    }

    queue<int> que;
    int s=0;
    dist[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        if(v%w!=w-1 && c[v+1] && dist[v+1]==-1){
            dist[v+1]=dist[v]+1;
            que.push(v+1);
        }
        if(v%w!=0 && c[v-1] && dist[v-1]==-1){
            dist[v-1]=dist[v]+1;
            que.push(v-1);
        }
        if(v/w!=h-1 && c[v+w] && dist[v+w]==-1){
            dist[v+w]=dist[v]+1;
            que.push(v+w);
        }
        if(v/w!=0 && c[v-w] && dist[v-w]==-1){
            dist[v-w]=dist[v]+1;
            que.push(v-w);
        }
    }
    int ans;
    if(dist[h*w-1]==-1) ans=-1;
    else ans=cnt-1-dist[h*w-1];
    cout << ans << "\n";
    return 0;
}