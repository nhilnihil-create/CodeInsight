#include <bits/stdc++.h>
#define foi(i,n) for(int i = 0; i < n ; ++i)
#define pi pair<int,int>
#define int long long
using namespace std;

void update(int val,int i,int s,int e,int index,int *tree){
    if(s>e) return ;
	if(s==e){
		if(i == s) tree[index] = val;
		return;
	}

	if(s>i || e < i) return;

	int mid = (s+e)/2;

	update(val,i,s,mid,2*index,tree);
	update(val,i,mid+1,e,2*index+1,tree);
	tree[index] = max(tree[2*index],tree[2*index+1]);
}

int get(int qs,int qe,int s,int e,int index,int *tree){
    if(s>e) return 0;
	if(qs>e || qe <s ) return 0;
	if(qs<=s && qe>=e) return tree[index];

	int mid = (s+e)/2;

	int left = get(qs,qe,s,mid,2*index,tree);
	int right = get(qs,qe,mid+1,e,2*index+1,tree);
	return max(left,right);
}


int32_t main(){

	int n;
	cin >> n;
	int *index = new int[n];
	int *bty = new int [n];
	int *tree= new int[5*n];
	foi(i,5*n) tree[i] = 0;
    foi(i,n) cin >> index[i];
    foi(i,n) cin >> bty[i];
	int answer = 0;
	int *output = new int[n];
	for(int i = 0; i < n ; i++){
		int val = bty[i];
		int ht = index[i];
		//cout << ht << " -- " << val << endl;
		int updateVal;
		if(ht == 1 ) updateVal = val;
		else updateVal = val + get(1,ht-1,1,n,1,tree);
		update(updateVal,ht,1,n,1,tree);
		answer = max(answer,updateVal);
		output[i] = updateVal;
	}
	cout << tree[1] << endl;


}
