//============================================================================
// Name        : d.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int n;cin>>n;
	int k;cin>>k;
	string s;cin>>s;
	vector<int> stand,hand;
	hand.push_back(0);
	hand.push_back(0);
	stand.push_back(0);

	int ex=1;
	for(int i=0;i<n;i++){
		s[i]-='0';
		if(ex==s[i]){
			if(ex==1){
				hand.back()++;
			}else{
				stand.back()++;
			}
		}else{
			if(ex==1){
				ex=0;
				stand.push_back(1);
			}else{
				ex=1;
				hand.push_back(1);
			}
		}
	}
	if(ex==0){
		hand.push_back(0);
	}

//	for(int i=0;i<stand.size();i++){
//		cout<<stand[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<hand.size();i++){
//		cout<<hand[i]<<' ';
//	}
//
//	cout<<endl;
	for(int i=1;i<stand.size();i++){
		stand[i]+=stand[i-1];
//			cout<<stand[i]<<' ';
	}
//	cout<<endl;
	for(int i=1;i<hand.size();i++){
		hand[i]+=hand[i-1];
//		cout<<hand[i]<<' ';
	}
//	cout<<endl;
	int ans=0;
	for(int i=k;i<stand.size();i++){
		int temp=stand[i]-stand[i-k]+hand[i+1]-hand[i-k];
		ans=max(ans,temp);
	}
	if(ans==0){
		ans=n;
	}


	cout<<ans<<endl;
	return 0;
}
