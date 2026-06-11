#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, A = 0, B = 0;
  	cin >> N;
  	vector <int> a(N);
  	for(int i = 0; i < N; i++){
    	cin >> a.at(i);
    }
  	sort(a.begin(),a.end());
  	int flag = 0;
  	for(int i = N - 1; i >= 0; i--){
    	if(flag == 0){
        	A += a.at(i);
          	flag = 1;
        }else{
        	B += a.at(i);
          	flag = 0;
        }
    }
  	cout << A - B << endl;
}
