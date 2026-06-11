#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
typedef long long ll;
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
int INF=2e+9+1;
int main(){
	int N;
	int a[50];
	int maxa=-INF,mina=INF;
	int argmaxa=-1,argmina=-1;
	scan(N);
	rep(i,N){
		scan(a[i]);
		if(a[i]>maxa){
			maxa=max(maxa,a[i]);
			argmaxa=i;
		}
		if(a[i]<mina){
			mina=min(mina,a[i]);
			argmina=i;
		}
	}
	int kaisu=0;
	if(mina>=0){
		prin(N-1);
		rep(i,N-1){
			printf("%d %d\n",i+1,i+2);
		}
	}
	else if(maxa<=0){
		prin(N-1);
		for(int i=N;i>1;i--){
			printf("%d %d\n",i,i-1);
		}
	}
	else if(abs(maxa)>=abs(mina)){
		prin(2*N-1);
		rep1(i,N){
			printf("%d %d\n",argmaxa+1,i);
		}
		rep(i,N-1){
			printf("%d %d\n",i+1,i+2);
		}
	}
	else{
		prin(2*N-1);
		rep1(i,N){
			printf("%d %d\n",argmina+1,i);
		}
		for(int i=N;i>1;i--){
			printf("%d %d\n",i,i-1);
		}
	}
	return 0;
}
