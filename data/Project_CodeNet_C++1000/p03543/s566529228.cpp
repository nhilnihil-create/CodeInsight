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


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int same = 0;
	for(int i=1; i<s.size(); i++){
		if(s[i] == s[i-1]){
			same++;
			if(same >= 2){
				break;
			}
		}
		else{
			same = 0;
		}
	}

	if(same >= 2){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
