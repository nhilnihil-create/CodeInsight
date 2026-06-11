#include <iostream>
#include <bits/stdc++.h>
using namespace std;  
int size=200000; 
vector<bool> used(size,false); 
 
 pair<int,int> BFS(vector<vector<int> > al,int s){ 
 	int n=al.size(); 
 	vector<int> d(n,0); 
	queue<int> q; 
 	q.push(s);  
 	used[s]=true; 
 	while(!q.empty() ){ 
		int v=q.front();  
 		 q.pop(); 
 		 for(int u: al[v]){ 
 		 	if(!used[u]){ 
 		 		d[u]=d[v]+1;  
 		 		used[u]=true; 
 		 		q.push(u);
			  }
		  }
	 } 
	 int m=0; 
	 int v; 
	 for(int i=0;i<n;i++){ 
	 	if(d[i]>m){ 
	 		m=d[i]; 
	 		v=i; 
		 }
	 } 
	 return pair<int,int>(m,v); 
 }
 
 int main(){
  	ios::sync_with_stdio(false);
    cin.tie(0);  
    int N; 
    cin>>N; 
	vector<vector<int> > al(N);  
    for(int i=1;i<N;i++){ 
    	int a,b; 
    	cin>>a>>b;
    	a--; 
    	b--;  
    	al[a].push_back(b); 
		al[b].push_back(a); 
		 
	}  
	
	pair<int,int> mv=BFS(al,0); 
	for(int i=0;i<N;i++){ 
		used[i]=false; 
	} 
	pair<int,int> mvf=BFS(al,mv.second); 
	int val=mvf.first;  
	if (val%3==1){ 
		cout<<"Second"; 
	}else{ 
		cout<<"First"; 
	}
	
    
    return 0; 
}
