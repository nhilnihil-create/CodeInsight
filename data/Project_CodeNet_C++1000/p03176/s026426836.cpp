#include<bits/stdc++.h>
using namespace std;
long long int maximum=0;
struct flower{
	long long int height;
	long long int beauty;
	int pos;
};
bool compare(flower a,flower b){
	return a.height>b.height;
}
void update_element(long long int *seg_tree,int start,int end,int node,int pos,long long int value){
	if(start==end){
		seg_tree[node]=value;
	}
	else{
		int mid=(start+end)/2;
		if(pos<=mid)
		update_element(seg_tree,start,mid,2*node,pos,value);
		else
		update_element(seg_tree,mid+1,end,2*node+1,pos,value);
		seg_tree[node]=max(seg_tree[2*node],seg_tree[2*node+1]);
	}
}
long long int sum(long long int *seg_tree,int start,int end,int node,int left,int right){
	if(right<start||left>end)
	return 0;
	else if(left<=start&&end<=right)
	return seg_tree[node];
	else{
		int mid=(start+end)/2;
		return max(sum(seg_tree,start,mid,2*node,left,right),sum(seg_tree,mid+1,end,2*node+1,left,right));
	}
}
void do_my_job(long long int *seg_tree,int start,int end,int node){
    if(start==end){
    	if(maximum<seg_tree[node]){
    		maximum=seg_tree[node];
		}
		//cout<<seg_tree[node]<<" "<<start<<endl;
	}
	else{
		int mid=(start+end)/2;
		do_my_job(seg_tree,start,mid,2*node);
		do_my_job(seg_tree,mid+1,end,2*node+1);
	}
}
int main(void){
	int n;
	cin>>n;
	long long int height[n];
	long long int arr[n];
	for(int i=0;i<n;i++){
		cin>>height[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	flower help[n];
	for(int i=0;i<n;i++){
		help[i].beauty=arr[i];
		help[i].height=height[i];
		help[i].pos=i+1;
	}
	sort(help,help+n,compare);
	long long int seg_tree[4*n]={0};
	for(int i=0;i<n;i++){
		int start=help[i].pos;
		int end=n-1;
		long long int value=sum(seg_tree,0,n-1,1,start,end);
        value+=help[i].beauty;
        //cout<<value<<endl;
        update_element(seg_tree,0,n-1,1,help[i].pos-1,value);
	}
	do_my_job(seg_tree,0,n-1,1);
	cout<<maximum<<endl;
}