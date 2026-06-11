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
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int S[4000][4000];
int main(){
	int N;
	scan(N);
	if(N==1){
		prin("Yes");prin(2);printf("1 1\n1 1\n");
	}
	else{
		if(fabs(round(sqrt(N*8+1))*round(sqrt(N*8+1))-(N*8+1))<eps){
			prin("Yes");
			int k=(int)((1.0+sqrt(N*8+1))/2+eps);
			prin(k);
			int Snum=k-1;
			int count=1;
			rep(i,k){
				rep(j,Snum){
					if(j>=i){
						S[i][j]=count;
						count++;
					}
					else{
						S[i][j]=S[j][i-1];
					}
				}
			}
			rep(i,k){
				printf("%d ",Snum);
				rep(j,Snum){
					printf("%d ",S[i][j]);
				}
				kaigyo;
			}
		}
		else{
			prin("No");
		}
	}
	return 0;
}
