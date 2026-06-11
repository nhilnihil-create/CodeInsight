#include <bits/stdc++.h>
using namespace std;
#define intl long long

int main() {
    int n;
    cin>>n;
    bool b=false;
    int r;
    for(int i=1;i<1000;i++){
    	if(i*(i+1)/2==n){
    		b=true;
    		r=i;
		}
	}
	if(b==false){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
		cout<<r+1<<endl;
		vector<vector <int>> v(r+1);
		v[0].push_back(1);
		v[1].push_back(1);
		for(int i=1;i<r;i++){
			int left=i*(i+1)/2;
			int right=(i+1)*(i+2)/2;
			int index=0;
			for(int j=left+1;j<=right;j++){
				v[index].push_back(j);
				v[i+1].push_back(j);
				index++;
			}
		}
		
		for(int i=0;i<r+1;i++){
			cout<<v[i].size()<<" ";
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}	
	}
	
}