#include<iostream>
#include<vector>
using namespace std;
const int INF=1e9+7;

int D,G;
int p[100],c[100];
vector<bool> used(10,false);

int dfs(int cur,int score,int s){
    if(cur==D){
        int res=0;
        if(s!=-1){
            while(score<G&&res<p[s]){
            score+=(s+1)*100;
            res++;
          }
        }
        if(score<G) return INF;
        return res;
    }
    int res1,res2;
    res1=dfs(cur+1,score+(cur+1)*100*p[cur]+c[cur],s)+p[cur];
    res2=dfs(cur+1,score,cur);
    return min(res1,res2);
}

int main(){
    cin>>D>>G;
    for(int i=0;i<D;i++){
        cin>>p[i]>>c[i];
    }
    cout<<dfs(0,0,-1)<<endl;
}