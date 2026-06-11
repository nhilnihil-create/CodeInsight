#include<cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string S, T;
	cin >> S >> T;
	int A[S.size()], B[T.size()];
	for (int i = 0; i < S.size(); ++i){
		A[i] = S[i] - 'a';
		B[i] = T[i] - 'a';
	}
	int first_appearance_of_alphabet_S[26], first_appearance_of_same_letter_S[S.size()];
	int first_appearance_of_alphabet_T[26], first_appearance_of_same_letter_T[T.size()];
	for (int i = 0; i < 26; ++i){
		first_appearance_of_alphabet_S[i] = first_appearance_of_alphabet_T[i] = -1;
	}
	bool flag = true;
	for (int i = 0; i < S.size(); ++i){
		if(first_appearance_of_alphabet_S[A[i]] < 0) first_appearance_of_alphabet_S[A[i]] = i;
		if(first_appearance_of_alphabet_T[B[i]] < 0) first_appearance_of_alphabet_T[B[i]] = i;
		first_appearance_of_same_letter_S[i] = first_appearance_of_alphabet_S[A[i]];
		first_appearance_of_same_letter_T[i] = first_appearance_of_alphabet_T[B[i]];
		if(first_appearance_of_same_letter_S[i] != first_appearance_of_same_letter_T[i]){
			flag = false;
			break;
		}
	}
	printf("%s\n", flag ? "Yes" : "No");
	return 0;
}