#include "bits/stdc++.h"
using namespace std;

#define ii pair<int,int> 
#define iii pair<ii,ii> 
#define state pair<ii,int> 

int X, Y, offset;
string str;
vector<int> moves[2];
bool fAns = false;
const int OFFSET = 8000;

bool ans[4005][2*OFFSET], found[4005][2*OFFSET];

bool dp(vector<int>& m, int pos, int diff){
	if(pos == m.size()){
		return (diff == OFFSET);
	}
	if(found[pos][diff]){
		return ans[pos][diff];
	}
	found[pos][diff] = true;
	return ans[pos][diff] = (dp(m, pos+1, diff+m[pos])|dp(m, pos+1, diff-m[pos]));
}

int main(){
	cin >> str;
	cin >> X >> Y;
	int cons = 0;
	bool onX = false, first = true;
	for(int i = 0; i < str.size(); ++i){
		if(str[i] == 'F')
			cons++;
		else{
			if(first){
				// Must be X positive
				offset = cons;
			}else{
				moves[onX].push_back(cons);
			}
			first = false;
			onX = !onX;
			cons = 0;
		}
	}
	if(first){
		// Must be X positive
		offset = cons;
	}else{
		moves[onX].push_back(cons);
	}
	// for(int i : moves[0]) printf("(%d\n", i); printf("\n");
	// for(int i : moves[1]) printf("[%d\n", i);
	fAns = (dp(moves[0], 0, OFFSET+X-offset));
	// printf("[%d] %d\n", dp(moves[0], 0, OFFSET+X-offset), X-offset);
	memset(found, 0, sizeof found);
	fAns &= (dp(moves[1], 0, OFFSET+Y));
	if(fAns)
		printf("Yes\n");
	else
		printf("No\n");
}