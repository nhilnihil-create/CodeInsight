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

int s[28] = {0};
int t[28] = {0};

int main(int argc, char* argv[]){
	string S, T;
	cin >> S;
	cin >> T;

	int N = S.size();
	int NG = 0;
	for(int i=0; i<N; i++){
		int u = S.at(i) - 'a';
		int v = T.at(i) - 'a';
		if(s[u] != 0 && s[u] != v){
			NG = 1;
			break;
		}
		s[u] = v;
		if(t[v] != 0 && t[v] != u){
			NG = 1;
			break;
		}
		t[v] = u;
	}
	if(NG == 1){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
	}
	return 0;
}