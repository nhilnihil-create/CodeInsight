#include<bits/stdc++.h>

using namespace std;

const int MAXN=2e5+6;

string ch;
int n;

int can=0;

struct side {
	int from,to,nex;
}edge[MAXN];
int head[MAXN],cntm;
void link(int from,int to) {
	edge[++cntm].from=from;
	edge[cntm].to=to;
	edge[cntm].nex=head[from];
	head[from]=cntm;
}

int N=2,root=1;

int main() {
	cin>>ch;
	n=ch.size();
	if(ch[n-1]=='1'||ch[n-2]=='0'||ch[0]=='0') {
		cout<<-1<<endl;
		return 0;
	}
	for(int i=2;i<=n/2;i++) {
		if(ch[i-1]=='0') {
			if(ch[n-i-1]=='1') {
				cout<<-1<<endl;
				return 0;
			}
			continue;
		}
		else {
			if(ch[n-i-1]=='0') {
				cout<<-1<<endl;
				return 0;
			}
			link(N,root);
			root=N;
			N++;
			while(N<=i) {
				link(root,N);
				N++;
			}
		}
	}
	if(n%2==0) {
		link(N,root);
		root=N;
		N++;
		while(N<=n) {
			link(root,N);
			N++;
		}
		for(int i=1;i<=cntm;i++) {
			cout<<edge[i].from<<" "<<edge[i].to<<endl;
		}
		return 0;
	}
	if(n%2==1) {
		link(N,root);
		root=N;
		N++;
		while(N<=n) {
			link(root,N);
			N++;
		}
		for(int i=1;i<=cntm;i++) {
			cout<<edge[i].from<<" "<<edge[i].to<<endl;
		}
		return 0;
	}
}