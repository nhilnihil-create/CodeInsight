#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

int d[210000];

int main(){
    int N;
    cin>>N;
    vector<int> V[210000];
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i=0;i<210000;i++) d[i]=-1;
    queue<int> que;
    que.push(0);
    d[0]=0;
    int num,L;
    while(!que.empty()){
        int now=que.front(); que.pop();
        for(int i=0;i<(int)V[now].size();i++){
            int next=V[now][i];
            if(d[next]==-1){
                d[next]=d[now]+1;
                que.push(next);
                num=next;
            }
        }
    }
    for(int i=0;i<210000;i++) d[i]=-1;
    que.push(num);
    d[num]=0;
    while(!que.empty()){
        int now=que.front(); que.pop();
        for(int i=0;i<(int)V[now].size();i++){
            int next=V[now][i];
            if(d[next]==-1){
                d[next]=d[now]+1;
                que.push(next);
                num=next;
                L=d[next];
            }
        }
    }
    //cout<<L<<endl;
    if(L%3==1) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}

