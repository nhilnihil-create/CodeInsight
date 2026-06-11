#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int switches[n]={0};
	int current_state = 0;
	for(int i=0; i<m; i++){
		int connected;
		cin>>connected;
		while(connected--){
			int swt;
			cin>>swt;
			swt--;
			switches[swt]|=(1<<i);
		}
	}
	for(int i=0; i<m; i++){
		bool turned;
		cin>>turned;
		if(!turned) current_state|=(1<<i);
	}
	int ret = 0;
	for(int state=0; state<(1<<n); state++){
		int final_state = 0;
		for(int j=0; j<n; j++){
			if(state&(1<<j)) final_state^=switches[j];
		}
		final_state^=current_state;
		if(final_state==((1<<m)-1)){
			ret++;
		}
	}
	cout<<ret;
}