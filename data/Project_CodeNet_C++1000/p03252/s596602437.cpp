#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;


int main()
{
	string S,T;
	cin>>S;
	cin>>T;
	vector<int> RS(26,-1);
	vector<int> RT(26,-1);
	bool ans = true;
	for(int i = 0; i < S.length(); i++){
		int s = S[i] - 'a';
		int t = T[i] - 'a';
		if( RS[s] < 0){
			RS[s] = t;
		}else{
			if( RS[s] != t){
				ans = false;
				break;
			}
		}
		if( RT[t] < 0){
			RT[t] = s;
		}else{
			if(RT[t] != s){
				ans = false;
				break;
			}
		}

	}
	if(ans == true){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
