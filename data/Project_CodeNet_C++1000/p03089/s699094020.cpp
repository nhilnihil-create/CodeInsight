#include <bits/stdc++.h>
using namespace std;

int N,a; vector<int> sol,v;

void Input(){
	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>a;
		v.push_back(a);
	}
}

void Solve(){
	bool solution=true;
	for(int j=0; j<N; j++){
		bool pos=false;
		for(int i=v.size()-1; i>=0; i--){
			if(v[i]==i+1){
				sol.push_back(v[i]);
				v.erase(v.begin()+i);
				pos=true;
				break;
			}
		}
		solution=solution&pos;
	}
	if(solution){
		for(int i=sol.size()-1; i>=0; i--){
			cout<<sol[i]<<'\n';
		}
	}else{
		cout<<-1<<'\n';
	}
}

int main(){
	Input();
	Solve();
}