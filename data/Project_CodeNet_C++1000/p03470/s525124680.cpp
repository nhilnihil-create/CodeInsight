#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++){
    	cin >> vec.at(i);
    }
  	sort(vec.begin(), vec.end());
  	reverse(vec.begin(), vec.end());
  	int x = vec.at(0), counter = 1;
  	for(int i = 0; i < N; i++){
    	if(x > vec.at(i)){
        	x = vec.at(i);
        	counter+=1;
        }
    }
  	cout << counter << endl;
}