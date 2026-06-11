#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int arr[505][505];

int main(){
	int h,w;
	cin>>h>>w;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++) cin>>arr[i][j];
	}
	int p = 0;
	int ret = 0;
	vector<pi>start; 
	vector<pi>fin;
	bool forward = true;
	for(int i=0; i<h; i++){
		if(forward){
			for(int j=0; j<w; j++){
				if(arr[i][j]%2 && !(i==h-1 && j==w-1)){
					ret++;
					start.push_back(pi(i,j));
					if(j==w-1){
						 fin.push_back(pi(i+1,j));
						 arr[i+1][j]++;
					}
					else{
						fin.push_back(pi(i,j+1));
						arr[i][j+1]++;
					}
				}
			}
		}
		else{
			for(int j=w-1; j>=0; j--){
				if(arr[i][j]%2 && !(i==h-1 && j!=0)){
					ret++;
					start.push_back(pi(i,j));
					if(j==0){
						 fin.push_back(pi(i+1,j));
						 arr[i+1][j]++;
					}
					else{
						fin.push_back(pi(i,j-1));
						arr[i][j-1]++;
					}
				}
			}
		}
	}
	cout<<ret<<'\n';
	for(int i=0; i<start.size(); i++){
		cout<<start[i].first+1<<" "<<start[i].second+1<<" "<<fin[i].first+1<<" "<<fin[i].second+1<<'\n';
	}
}