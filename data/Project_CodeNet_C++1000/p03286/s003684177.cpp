#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
using namespace std;
int main(){
	long long n;
	vector<int> ans;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
	}else{
		int now=0;
		while(n!=0){
			if(now%2==0&&n==(1LL<<now)){
				ans.push_back(1);
				break;
			}else if(now%2==1&&n==-(1LL<<now)){
				ans.push_back(1);
				break;
			}else if(n%(1LL<<(now+1))==0){
				ans.push_back(0);
			}else{
				ans.push_back(1);
				if(now%2==0){
					n-=(1LL<<now);
				}else{
					n+=(1LL<<now);
				}
			}
			now++;
		}
	}
	for(int  i=0;i<ans.size();i++){
		cout<<ans[ans.size()-1-i];
	}
	cout<<endl;
	return 0;
}
