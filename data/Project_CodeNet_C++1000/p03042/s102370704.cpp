#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	char* S = (char*)calloc(5, sizeof(char));
	cin >> S;
	
	string ans;
	
	char* first = (char*)calloc(3, sizeof(char));
	first[0] = S[0]; first[1] = S[1];
	char* second = (char*)calloc(3, sizeof(char));
	second[0] = S[2]; second[1] = S[3];
	
	int f = atoi(first);
	int s = atoi(second);
	
	if(0 < f && f < 13){
		if(0 < s && s < 13) ans = "AMBIGUOUS";
		else ans = "MMYY";
	}
	else{
		if(0 < s && s < 13) ans = "YYMM";
		else ans = "NA";
	}
	
	cout << ans << endl;
	
}