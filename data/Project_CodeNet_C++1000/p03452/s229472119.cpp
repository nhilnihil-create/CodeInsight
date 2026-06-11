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

int main(){
    int N,M;
    int L[200000],R[200000],D[200000];
    cin>>N>>M;
    rep(i,M) cin>>L[i]>>R[i]>>D[i];
    vector<pair<int,int>> vec[100000];
    rep(i,M){
        vec[L[i]-1].push_back(make_pair(R[i]-1,D[i]));
        vec[R[i]-1].push_back(make_pair(L[i]-1,-1*D[i]));
    }
    bool done[100000];
    int pos[100000];
    queue<int> que;
    int now,next;
    rep(i,N){
        if(done[i]) continue;
        pos[i]=0;
        done[i]=true;
        que.push(i);
        while(!que.empty()){
            now=que.front();
            que.pop();
            while(!vec[now].empty()){
                next=vec[now].back().first;
                if(done[next]) {
                    vec[now].pop_back();
                    continue;
                }
                done[next]=true;
                pos[next]=pos[now]+vec[now].back().second;
                que.push(next);
                vec[now].pop_back();
            }
        }
    }
    rep(i,M){
        if((pos[R[i]-1]-pos[L[i]-1])!=D[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}