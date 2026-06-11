#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<string,int> Pa;
int main(){
	vector<Pa> vec;
	int T[101]={0};
	int N,P;
	string S;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>S>>P;
		T[P]=i+1;
		vec.push_back(Pa(S,-P));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<N;i++)cout<<T[-vec[i].second]<<endl;
	return 0;
}