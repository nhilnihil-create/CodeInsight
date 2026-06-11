#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
    cin >> N;
	vector<int> kagamimochi(N);
    for(int i = 0; i < N; i++){
    	cin >> kagamimochi.at(i);
    }
    int Max , Count;
    Count = 0;
    for(int i = 0; i < N; i++){
    	Max = kagamimochi.at(i);
        for(int j = 0; j < N; j++){
        	if(Max < kagamimochi.at(j)){
            	Max = kagamimochi.at(j);
            }
        }
        if(Max == 0){
        	break;
        }
        for(int k = 0; k < N; k++){
        	if(kagamimochi.at(k) == Max){
            	kagamimochi.at(k) = 0;
            }
        }
        Count++;
    }
  	cout << Count << endl;
}