#include <iostream>
#include <vector>
using namespace std;

vector <long long> positions;

void solution(){
	long long res = 0;
	for(long long i = 0; i < positions.size(); i++){
		res += positions[i];
	}
	cout << res << endl;
}

int main(){
	string s;
	cin >> s;

	long long counter = 0; 
	for(long long i = 0; i < s.size(); i++){
		if(s[i] == 'B') counter++;
		else positions.push_back(counter);
	}

	solution();
}