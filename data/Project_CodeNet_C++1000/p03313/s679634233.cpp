#include<bits/stdc++.h>
using namespace std;

int used[300000];

int main(){
	int N;
	cin >> N;
	int A[(1<<N)+1];
	for(int i=0; i<(1<<N); i++){
		cin >> A[i];
	}
	A[1<<N] = -1;
	long long data[1<<N][2];
	data[0][0] = 0; data[0][1] = -1;
	for(int i=1; i<(1<<N); i++){
		vector<int> arr;
		arr.push_back(i);
		for(int j=0; j<N; j++){
			if(i & (1<<j)){
				int bit = i &~(1<<j);
				if(used[data[bit][0]] == 0){
					used[data[bit][0]] = 1;
					arr.push_back(data[bit][0]);
				}
				if(data[bit][1] != -1){
					if(used[data[bit][1]] == 0){
						arr.push_back(data[bit][1]);
						used[data[bit][1]] = 1;
					}
				}
			}
		}
		int ma = (1<<N), ma2 = (1<<N);
		for(int j=0; j<arr.size(); j++){
			if(A[ma] < A[arr[j]]) ma = arr[j];
		}
		for(int j=0; j<arr.size(); j++){
			if(arr[j] != ma){
				if(A[ma2] < A[arr[j]]) ma2 = arr[j];
			}
		}
		data[i][0] = ma, data[i][1] = ma2;
		for(int j=0; j<arr.size(); j++){
			used[arr[j]] = 0;
		}
	}
	int ans[1<<N];
	ans[0] = 0;
	for(int i=1; i<(1<<N); i++){
		ans[i] = max(ans[i-1], A[data[i][0]] + A[data[i][1]]);
		cout << ans[i] << endl;
	}
	return 0;
}