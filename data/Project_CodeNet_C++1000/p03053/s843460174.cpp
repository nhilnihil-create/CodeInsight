#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

vector<pair<long long, long long> > G[1000][1000];
bool val[1000][1000];

long long dep_max=0;

int main(){
    //input
    long long H,W;
    cin >> H >> W;
    string S;
    vector<string> A;
    long long i,j;
    for(i=0; i<H; i++){
        cin >> S;
        A.push_back(S);
    }

    //calc
    pair<pair<long long, long long>, long long> p;
    queue<pair<pair<long long, long long>, long long> > que;
    long long x,y,z,s,t;
    for(i=0; i<H; i++){
        for(j=0; j<W-1; j++){
            G[i][j].push_back(make_pair(i,j+1));
            G[i][j+1].push_back(make_pair(i,j));
        }
    }
    for(j=0; j<W; j++){
        for(i=0; i<H-1; i++){
            G[i][j].push_back(make_pair(i+1,j));
            G[i+1][j].push_back(make_pair(i,j));
        }
    }
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            val[i][j]=0;
        }
    }
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(A[i][j]=='#'){
                val[i][j]=1;
                que.push(make_pair(make_pair(i,j),0));
            }
        }
    }
    while(!que.empty()){
        p=que.front();
        que.pop();
        dep_max=max(p.second,dep_max);
        x=p.first.first;
        y=p.first.second;
        z=p.second;
        for(i=0; i<G[x][y].size(); i++){
            s=G[x][y][i].first;
            t=G[x][y][i].second;
            if(val[s][t]==0){
                val[s][t]=1;
                que.push(make_pair(make_pair(s,t),z+1));
            }
        }
    }


    //answer
    cout << dep_max << endl;
    system("pause");
    return 0;
}