#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;
int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	int red = 0;
	int blue = 0;
	for(int i=0;i<N;i++){
		if(S[i] == 'R')red++;
		else blue++;
	}
	if(red > blue) cout << "Yes" << endl;
	else cout << "No" << endl;
}