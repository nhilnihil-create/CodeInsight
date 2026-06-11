#include<iostream>
using namespace std;

int main(){
	string S;
	cin >> S;
	bool test=true;
	int cCnt=0;

	for(int i=0;i<S.length();i++){
		if(i==0){
			if(S[i]!='A'){
				test=false;
			}
		}else if(2<=i && i<=S.length()-2){
			if(S[i]=='C'){
				cCnt++;
			}else{
				if(S[i]<'a' || 'z'<S[i]){
					test=false;
				}
			}
		}else{
			if(S[i]<'a' || 'z'<S[i]){
				test=false;
			}
		}
	}
	if(cCnt!=1){
		test=false;
	}
	if(test){
		cout << "AC" << endl;
	}else{
		cout << "WA" << endl;
	}
	return 0;
}
