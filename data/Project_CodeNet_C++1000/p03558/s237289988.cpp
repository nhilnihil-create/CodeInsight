#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

const int MAXN =1e5+10;

int k;
struct VER{
	int x,w;
};
bool vis[MAXN];
deque<VER> q;

void bfs(){
	VER v;
	v.w=1;//为什么起点是1，权值也是1? 
	v.x=1;
	q.push_front(v);
	
	while(!q.empty()){
		VER t=q.front();
		q.pop_front();
		vis[t.x]=true;
		if(t.x==0){//是k的倍数 
			cout<<t.w<<endl;
			break;
		}
		if(!vis[t.x*10%k]){
			VER m;
			m.x=t.x*10%k;
			m.w=t.w;
			q.push_front(m);
		}
		
		if(!vis[(t.x+1)%k]){
			VER m;
			m.x=(t.x+1)%k;
			m.w=t.w+1;
			q.push_back(m);
		}
		
	}
	
}

int main(){
    cin>>k;
    bfs();
    
    return 0;
} 