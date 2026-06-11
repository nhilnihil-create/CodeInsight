#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,aa=0,bb=0,j=0,k=0,l=0,s,t,u,v;
    cin>>n;
    vector<int> A(100005,0),B(100005,0),AA(100005,-1),BB(100005,-1);
    for(int i=0;i<n/2;i++){
    	cin>>a>>b;
        A[a-1]++; 
        B[b-1]++;
        aa=max(aa,A[a-1]);
        bb=max(bb,B[b-1]);
    }
    for(int i=0;i<100005;i++){
    	if(A[i]==aa) {
          AA[j]=i;j++;
        }
        if(B[i]==bb){
          BB[k]=i;k++;
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());
    if(AA[100004]!=BB[100004]){
      cout<<n-aa-bb;
    }
    else{
      cout<<min(n-A[100004]-B[100003],n-A[100003]-B[100004]);
    }
}
 
