#include <iostream>
using namespace std;
int main(){
	string S, T;
	cin >> S >> T;
	
	int len = S.length();
	int Tindex;
	
	int i, index;
	bool flag = false;
	for(i = 0; i < len; i++){
		if(flag == 1)
			break;
		if(T[i] == S[0]){
			for(index = 1; index < len; index++){
				if(i + index >= len)
					Tindex = i + index - len;
				else
					Tindex = i + index;
				if(T[Tindex] != S[index])
					break;
			}
			if(index == len)
				flag = 1;
		}
	}
	
	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
} 