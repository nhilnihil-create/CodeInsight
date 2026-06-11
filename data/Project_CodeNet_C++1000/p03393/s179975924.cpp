#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int main(){
	string S;
	cin >> S;

	if(S=="zyxwvutsrqponmlkjihgfedcba"){
		cout << -1 <<endl;
		return 0;
	}

	int N = S.size();
	if(N==26){
		int i = 25;
		while(S[i]>S[i+1]){
			i--;
		}
		for(int k=0;k<i;k++){
			cout << S[k];
		}
		int k = 25;
		while(S[k]<S[i]){
			k--;
		}
		cout << S[k] <<endl;
		
		return 0;
	}

	bool flag[26];
	for(int i=0;i<26;i++) flag[i] = false;

	for(int i=0;i<N;i++){
		flag[S[i]-'a'] = true;
	}

	cout << S;
	for(int i=0;i<26;i++){
		if(flag[i]==false){
			cout << char(i+'a') <<endl;
			break;
		}
	}
   
  	return 0;
}

