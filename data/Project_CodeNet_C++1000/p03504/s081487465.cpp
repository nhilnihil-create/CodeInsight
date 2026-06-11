#include<iostream>
using namespace std;

int main() {
	int N, C;
	cin>>N>>C;
	int schedule[C][100010];
	for(int i=0;i<C;++i){
		for(int j=0;j<1e5+10;++j){
			schedule[i][j] = 0;
		}
	}
	int s, t, c;
	for(int i=0;i<N;++i){
		cin>>s>>t>>c;
		c--;
		schedule[c][s]++;
		schedule[c][t+1]--;
	}

	/**
	for(int i=0;i<C;++i){
		for(int j=0;j<1e5+10;++j){
			cout<<schedule[i][j]<<" ";
		}
		cout<<endl;
	}
	**/

	for(int i=0;i<C;++i){
		for(int j=0;j<1e5+9;++j){
			schedule[i][j+1] += schedule[i][j]; 
		}
	}

	for(int i=0;i<C;++i){
		for(int j=0;j<1e5+9;++j){
			if(schedule[i][j]>0)schedule[i][j] = 1;
		}
	}

	int ans = 0;
	int tmp;
	for(int j=0;j<1e5+5;++j){
		tmp = 0;
		for(int i=0;i<C;++i){
			tmp += schedule[i][j];
		}
		if(ans<tmp)ans=tmp;
	}
	/**
	for(int i=0;i<C;++i){
		for(int j=0;j<1e5+10;++j){
			cout<<schedule[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	**/
	cout<<ans<<endl;
}
