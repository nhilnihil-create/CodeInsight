#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long
#define sz 200100


int tree[4 * sz];



int get(int s,int e,int qs,int qe,int idx){

	if(qs>e || qe<s || qs>qe)
		return 0;

	if(qs<=s && qe>=e){
		return tree[idx] ;
	}

	int mid=s+(e-s)/2;
	int a=get(s,mid,qs,qe,2*idx+1);
	int b=get(mid+1,e,qs,qe,2*idx+2);

	return max(a,b) ;
}

void upd(int s,int e,int idx,int val,int node){

	if(s > idx || e < idx)
		return ;

	if(s==e){
		tree[node]=val;
		return ;
	}

	int mid=s+(e-s)/2;
	upd(s,mid,idx,val,2*node+1);
	upd(mid+1,e,idx,val,2*node+2);
	tree[node]=max(tree[2*node+1],tree[2*node+2]);


}

signed main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
// online submission
#endif

memset(tree,0,sizeof tree);

int n;
cin >> n;

int h[n];
int a[n];
for(int i=0;i<n;i++)
	cin >> h[i];
for(int i=0;i<n;i++)
	cin >> a[i];


for(int i=0;i<n;i++){

	int m=get(0,n,0,h[i],0);

	upd(0,n,h[i],a[i]+m,0);
}


cout<<tree[0];


    return 0;
}


