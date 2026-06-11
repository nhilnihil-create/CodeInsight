#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int c[25];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int now=i;
		while(now!=1){
			for(int j=0;j<25;j++){
				if(now%p[j]==0){
					while(now%p[j]==0){
						now/=p[j];
						c[j]++;
					}
				}
			}
		}
	}
	for(int i=0;i<25;i++){
		if(c[i]){
			c[i]++;
		}
	}
	int th=0,fi=0,zy=0,ni=0,na=0;
	for(int i=0;i<25;i++){
		if(c[i]>=3){
			th++;
		}
		if(c[i]>=5){
			fi++;
		}
		if(c[i]>=15){
			zy++;
		}
		if(c[i]>=25){
			ni++;
		}
		if(c[i]>=75){
			na++;
		}
	}
	int ans=0;
	ans+=na;
	ans+=ni*(th-1);
	ans+=zy*(fi-1);
	ans+=fi*(fi-1)/2*(th-2);
	cout<<ans<<endl;
	return 0;
}
