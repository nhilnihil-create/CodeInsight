/**************************
*                         *
*  Nothing Is Impossible  *
*                         *
**************************/
#include <algorithm>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <thread>
#include <math.h>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <set>
#include <map>
#define GetRand(Min, Max) ((rand()%(int)(((Max) + 1)-(Min))) + (Min))
#define Rep(i, min, max) for(int i = min; i < max; ++i)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
using namespace std;

void Solve(){
	string s;	cin >> s;
	int Won = 0, Loses = 0;
	Rep(i,0,s.size()){
		if(s[i] == 'o'){
			Won++;
		}else{
			Loses++;
		}
	}
	if(Won >= 8){
		cout << "YES" << endl;
	}else if(Won+(15 - s.size()) >= 8){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}

int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}