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
	string S;
	int K;

	cin >> S;
	cin >> K;
	
	int len = S.size();
	const string ALPH = "abcdefghijklmnopqrstuvwxyz";

	map<char, vector<int>> mp;

	for(int i=0; i<S.size(); i++){
		char c = S[i];
		if(mp.count(c)==0){
			vector<int> v;
			v.push_back(i);
			mp[c] = v;
		}
		else{
			mp[c].push_back(i);
		}
	}

	map<string, int> mpstr;

	int count = 0;
	for(int i=0; i<ALPH.size(); i++){
		if(mp.count(ALPH[i]) == 0) continue;
		count++;
		vector<int> v = mp[ALPH[i]];
		for(int j=0; j<v.size(); j++){
			int k = v[j];
			//S[k]から始まる部分文字列をmpstrに入れる。
			//ただし、最大でK個まで
			int tmp = 0;
			for(int s = 1; s < len - v[j] + 1; s++){
				string str = S.substr(k, s);
				mpstr.insert(make_pair(str, 1));
				tmp++;
				if(tmp == K) break;
			}

		}
		if(count == K) break; 
	}

	count = 0;
	char ans[6] = {0};
	for(auto itr = mpstr.begin(); itr != mpstr.end(); itr++){
		string key = itr->first;
		count++;
		if(count == K){
			strcpy(ans, key.c_str());
			break;
		}
	}
	printf("%s\n", ans);
	return 0;
}