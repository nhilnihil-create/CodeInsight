#include<bits/stdc++.h>
using namespace std;
int find(int n,vector<int>&root){
    if(root[n]==n)return n;
    else return find(root[n],root);
}
int main(){
    long long n,m;
    cin>>n>>m;
    int A[m],B[m];
    for(int i=0;i<m;i++)cin>>A[i]>>B[i];
    long long x=n*(n-1)/2;
    vector<int>root(n);
    vector<int>rank(n,0);
    vector<long long>size(n,1);
    vector<long long>ans(m);
    for(int i=0;i<n;i++)root[i]=i;
    for(int i=m-1;i>=0;i--){
        ans[i]=x;
        int a=find(A[i]-1,root);
        int b=find(B[i]-1,root);
        if(a==b)continue;
        x-=size[a]*size[b];
        if(rank[a]<rank[b]){
            root[a]=b;
            size[b]+=size[a];
        }
        else{
            root[b]=a;
            size[a]+=size[b];
            if(rank[a]==rank[b])rank[a]++;
        }
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<endl;
    return 0;
}