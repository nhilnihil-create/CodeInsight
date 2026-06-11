#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int>> c(3, vector<int>(3));
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> c.at(i).at(j);
		}
	}
	vector<int> a(3), b(3);
	bool finish=0;
	a.at(0)=0;
	for(int i=0; i<3; i++){
		b.at(i)=c.at(0).at(i);
		a.at(i)=c.at(i).at(0)-b.at(0);
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(c.at(i).at(j)!=a.at(i)+b.at(j)){
				finish=1;
				break;
			}
		}
		if(finish){
			break;
		}
	}
	if(finish){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
	}
}

