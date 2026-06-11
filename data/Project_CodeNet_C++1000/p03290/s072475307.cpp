#include<iostream>
#include<vector>
const int INF=1e9+7;

using namespace std;
int D,G;
vector<int> p(10),c(10);

int dfs(int cur,int score,int f){
    if(cur==D){
        int res=0;
        if(f!=-1){
            while(score<G&&res<p[f]){
            score+=(f+1)*100;
            res++;
            }
        }
        if(score<G) return INF;
        return res;
    }
    int r1,r2;
    r1=dfs(cur+1,score+(cur+1)*100*p[cur]+c[cur],f)+p[cur];
    r2=dfs(cur+1,score,cur);
    return min(r1,r2);
}

int main(){
    cin>>D>>G;
    for(int i=0;i<D;i++) cin>>p[i]>>c[i];
    cout<<dfs(0,0,-1)<<endl;
    return 0;
}