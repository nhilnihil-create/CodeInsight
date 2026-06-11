#include<bits/stdc++.h>
using namespace std;
using v1 = vector<int>;
using v2 = vector<vector<int>>;

int main(){
	v2 c(3, vector<int>(3));
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			cin >> c.at(i).at(j);
		}
	}
	bool judge = true;
	int sum1_1 = c.at(0).at(0) + c.at(1).at(1);
	int sum1_2 = c.at(0).at(1) + c.at(1).at(0);
	if(sum1_1 != sum1_2){
		judge = false;
	}else{
		int sum2_1 = c.at(2).at(2) + sum1_1;
		double sum2_2 = c.at(1).at(2) + c.at(0).at(2) + c.at(2).at(0) +c.at(2).at(1) +sum1_2;
		 if(sum2_1 != (sum2_2/2.0)) judge = false;
		}
		if(judge) cout << "Yes" << endl;
		if(!judge) cout << "No" << endl;
}
