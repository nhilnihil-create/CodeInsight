# include <bits/stdc++.h>
using namespace std;
int n,m,x,y,A[200005],B[200005],k,t,f[200005];
vector <int>v[200005];
string s;
queue<int>q;
int main (){
	cin>>n>>m>>s;
	for (int i=0; i<m; i++){
		cin>>x>>y; x--; y--;
		if (x==y)if(s[x]=='A')A[x]=1000000;else B[x]=1000000;
		else{
			if (s[x]=='A') A[y]++; else B[y]++;
			if (s[y]=='A') A[x]++; else B[x]++;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	for (int i=0; i<n; i++)if (A[i]*B[i]==0)q.push(i),f[i]=1;
	
	while(q.size()){
		k=q.front();
		q.pop();
		if (s[k]=='A') 
			for (int i=0; i<v[k].size(); i++){
				A[v[k][i]]--; 
				if (A[v[k][i]]<=0 && f[v[k][i]]==0)q.push(v[k][i]),f[v[k][i]]=1;
				}
		else	
			for (int i=0; i<v[k].size(); i++){
				B[v[k][i]]--; 
				if (B[v[k][i]]<=0 && f[v[k][i]]==0)q.push(v[k][i]),f[v[k][i]]=1;
				}	
	}
	for (int i=0; i<n; i++)if(A[i]>0 && B[i]>0){cout<<"Yes";return 0;}
	cout<<"No";
	return 0;
}