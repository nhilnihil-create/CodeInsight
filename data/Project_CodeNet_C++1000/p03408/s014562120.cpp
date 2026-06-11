#include <bits/stdc++.h>
using namespace std;

int main() {
	int N , M;
  	cin >> N;
  	vector<string> blue(N);
  	for(int i = 0; i < N; i++){
    	cin >> blue.at(i);
    }
  	cin >> M;
  	vector<string> red(M);
  	for(int i = 0; i < M; i++){
    	cin >> red.at(i);
    }
  	int max = 0;
    int counter;
  	string temp;
  	for(int i = 0; i < N; i++){
    	counter = 0;
      	temp = blue.at(i);
      	for(int j = 0; j < N; j++){
        	if(blue.at(j) == temp){
            	counter++;
            }
        }
      	for(int k = 0; k < M; k++){
        	if(red.at(k) == temp){
            	counter--;
            }
        }
      	if(max < counter){
        	max = counter;
        }
    }
  	cout << max << endl;
}