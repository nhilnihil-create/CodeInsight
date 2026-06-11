#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
long long int mod = 1e9+7;
int main(){
	int n;
	cin>>n;
	vector<int> map(26,1);
	char tmp;
	rep(i,n){
		cin>>tmp;
		map[tmp-'a']+=1;
	}
	long long int sum = 1;
	rep(i,26){
		sum = (sum*map[i])%mod;
	}
	cout<<(sum-1)%mod<<endl;
	return 0;
}