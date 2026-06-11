#include<iostream>
#include<string>
using namespace std;

int main(){
	string row;
	int i = 0;
	int cnt = 0;

	cin >> row;

	for(i=0;i<row.size();i++){
		if(row.at(i) == '1'){
			cnt++;
		}
	}

	cout << cnt << endl;
}