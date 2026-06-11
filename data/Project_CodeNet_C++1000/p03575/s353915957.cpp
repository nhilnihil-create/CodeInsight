#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    int ans=0;
    vector<int> edge[2000];
    int lis[100][2];
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        lis[i][0]=a;lis[i][1]=b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    queue<int> Q;
    for(int i=0;i<M;i++){
        int itta[100]={0};
        itta[1]=1;
        Q.push(1);
        while(!Q.empty()){
            int pa;
            pa=Q.front();Q.pop();
            for(int j=0;j<edge[pa].size();j++){
                if(itta[edge[pa][j]]==0){
                    if(pa==lis[i][0]&&edge[pa][j]==lis[i][1])continue;
                    if(pa==lis[i][1]&&edge[pa][j]==lis[i][0])continue;
                    itta[edge[pa][j]]=1;
                    Q.push(edge[pa][j]);

                }
            }
        }
        for(int j=1;j<=N;j++){
            if(itta[j]==0){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
