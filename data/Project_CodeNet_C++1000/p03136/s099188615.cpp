#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,m;
	vector<int> sides;
	cin>>n;
	for(vector<int>::size_type i=0;i!=n;++i){
		cin>>m;
		sides.push_back(m);
	}
	sort(sides.begin(),sides.end());
	int sum=0;
	for(vector<int>::size_type i=0;i!=n-1;++i){
		sum+=sides[i];
	}
	if(sum>sides[n-1])
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
		
}