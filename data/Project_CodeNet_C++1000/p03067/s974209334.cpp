#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;

	if (a > b){
		if (a > c){
			if (c > b){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
		else{
			cout << "No" << endl;
		}
	}

	else if (a < b){
		if (a < c){
			if (c < b){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
		else{
			cout << "No" << endl;
		}
	}


	return 0;
}