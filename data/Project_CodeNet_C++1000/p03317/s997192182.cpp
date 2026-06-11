#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr;
	while(n--){
		int a;
		cin>>a;
		arr.push_back(1);
	}
	int ret = 0;
	while(arr.size()){
		ret++;
		for(int i=0; i<k && arr.size(); i++) arr.pop_back();
		if(arr.size()) arr.push_back(1);
	}
	cout<<ret;
}