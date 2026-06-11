#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
using Graph = vector<vector<int>>;

char T[52] = {0};
char S[52] = {0};

int mymatch(char *s, char *t){
	int len1 = strlen(s);
	int len2 = strlen(t);
	if(len1 < len2) return 0;

	int match = 0;
	int i, j;
	for(i = (len1 - len2); i >= 0; i--){
		int b = 1;
		for(j = i; j < i + len2; j++){
			if(s[j] == '?' || s[j] == t[j-i]){
				continue;
			}
			else{
				b = 0;
				break;
			}
		}
		if(b == 1){
			match = 1;
			break;
		}
	}
	if(match == 1){
		strncpy(s + i, t, len2);
	}
	return match;
}

int main(int argc, char* argv[]){
	scanf("%s", S);
	scanf("%s", T);

	int ret = mymatch(S, T);
	if(ret == 0){
		printf("UNRESTORABLE\n");
	}
	else{
		for(int i=0; i<50; i++){
			if(S[i] == '?'){ S[i] = 'a'; }
		}
		printf("%s\n", S);
	}
	return 0;
}