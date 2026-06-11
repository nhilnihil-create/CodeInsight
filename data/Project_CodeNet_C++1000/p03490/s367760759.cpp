#include <bits/stdc++.h>
using namespace std;

char str[10001];
int vis[2][16001];

bool solve(int s,vector<int> arr,int t) {
    s+=8000;t+=8000;
    memset(vis,-1,sizeof(vis));
    vis[0][s]=0;
    
    int cur=1,pr=0;
    queue<int> que;
    que.push(s);
    for(int i=0;i<(int)arr.size();i++) {
        int s=(int)que.size();
        while(s--) {
            int p=que.front();que.pop();
            if(p+arr[i]<=16000 && vis[cur][p+arr[i]]!=i+1) {
                vis[cur][p+arr[i]]=i+1;
                que.push(p+arr[i]);
            }
            if(p-arr[i]>=0 && vis[cur][p-arr[i]]!=i+1) {
                vis[cur][p-arr[i]]=i+1;
                que.push(p-arr[i]);
            }
        }
        swap(cur,pr);
    }
    return vis[pr][t]==(int)arr.size();
}
int main() {
    int x,y;
    scanf("%s%d%d",str,&x,&y);
    vector<int> arr[2];
    int idx=0,n=strlen(str);
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(str[i]=='F') cnt++;
        else{
            arr[idx].push_back(cnt);
            cnt=0;
            idx^=1;
        }
    }
    arr[idx].push_back(cnt);

    puts(solve(arr[0][0],vector<int>(arr[0].begin()+1,arr[0].end()),x) && solve(0,arr[1],y) ? "Yes" : "No");
    
    return 0;
}
