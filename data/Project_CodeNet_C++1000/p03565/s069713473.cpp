#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){
	string S, T;
	cin >> S >> T;
	bool flag = false;
	int begin;
	for (begin = S.size() - T.size(); begin >= 0; --begin){
		flag = true;
		for (int j = 0; j < T.size(); ++j){
			if(S[begin + j] != '?' && S[begin + j] != T[j]){
				flag = false;
				break;
			}
		}
		if(flag) break;
	}
	if(!flag){
		printf("UNRESTORABLE\n");
		return 0;
	}
	for (int i = 0; i < begin; ++i){
		if(S[i] == '?') S[i] = 'a';
	}
	for (int i = begin; i < begin + T.size(); ++i){
		if(S[i] == '?') S[i] = T[i - begin];
	}
	for (int i = begin + T.size(); i < S.size(); ++i){
		if(S[i] == '?') S[i] = 'a';
	}
	for (int i = 0; i < S.size(); ++i){
		printf("%c", S[i]);
	}
	printf("\n");
	return 0;
}