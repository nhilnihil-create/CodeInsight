#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

int main(){
	string s;
	cin >> s;
	
	map<int,int> M;
	int sum = 0;
	M.insert(P(0,1));
	for(int j = 0 ; j < 26 ; j ++)M.insert(P(1<<j,1));
	for(int i = 0 ; i < s.size() ; i ++){
		sum ^= (1<<(s[i]-'a'));
		int ans = M[sum];
		for(int j = 0 ; j < 26 ; j ++){
			if(M.find(sum^(1<<j)) == M.end()){
				M[sum^(1<<j)] = ans+1;
			}
			else M[sum^(1<<j)] = min( M[sum^(1<<j)] , ans+1 );
		}
	}
	cout << M[sum] << endl;
}

