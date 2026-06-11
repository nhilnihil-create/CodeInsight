#include <iostream> 
 
using namespace std; 
 
int main(){ 
	int n;
	cin >> n;
	int a_1[n];
	int a_2[n];
	for(int i = 0; i < n; i++){
		cin >> a_1[i];
	}
	for(int i = 0; i < n; i++){
		cin >> a_2[i];
	}
	
	int ans[n];
	int max_ans = 0;
	for(int i = 0; i < n; i++){
		ans[i] = 0;
		for(int j = 0; j < n; j++){
			if(j == i) ans[i] += a_1[j] + a_2[j];
			else if(j > i) ans[i] += a_2[j];
			else if(j < i) ans[i] += a_1[j];
		}
		max_ans = (ans[i] > max_ans)?ans[i]:max_ans;
	}
	cout << max_ans << endl;
}
