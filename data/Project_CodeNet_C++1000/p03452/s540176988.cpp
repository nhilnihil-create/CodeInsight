#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

void search(int pos,bool *done,bool *edge_done,queue<int> &que,vector<pair<int,int>> *vec){
    pair<int,int> p;
    while(!vec[pos].empty()){
        p=vec[pos].back();
        vec[pos].pop_back();
        if(edge_done[p.second])continue;
        else{
            que.push(p.second);
            edge_done[p.second]=true;
            search(p.first,done,edge_done,que,vec);
        }
    }
    done[pos]=true;
}

int main(){
    int N,M;
    int L[200000],R[200000],D[200000];
    cin>>N>>M;
    rep(i,M) cin>>L[i]>>R[i]>>D[i];
    vector<pair<int,int>> vec[100000];
    rep(i,M){
        vec[L[i]-1].push_back(make_pair(R[i]-1,i));
        vec[R[i]-1].push_back(make_pair(L[i]-1,i));
    }
    queue<int> que;
    bool done[100000];
    bool edge_done[200000];
    rep(i,N){
        if(done[i]) continue;
        search(i,done,edge_done,que,vec);
    }
    bool fix[100000];
    ll pos[100000];
    int num;
    while(!que.empty()){
        num=que.front();
        que.pop();
        if(!fix[L[num]-1] && !fix[R[num]-1]){
            pos[L[num]-1]=0;
            pos[R[num]-1]=D[num];
            fix[L[num]-1]=true;
            fix[R[num]-1]=true;
        }else if( !fix[L[num]-1] ){
            pos[L[num]-1]=pos[R[num]-1]-D[num];
            fix[L[num]-1]=true;
        }else if(!fix[R[num]-1]){
            pos[R[num]-1]=pos[L[num]-1]+D[num];
            fix[R[num]-1]=true;
        }else{
            if((pos[R[num]-1]-pos[L[num]-1])!=D[num]) {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;

    
    return 0;
}
