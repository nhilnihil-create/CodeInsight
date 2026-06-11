#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		int base = 0;
		vector<int> res;
		if(N == 3){
			res.push_back(2);
			res.push_back(5);
			res.push_back(63);
			N = 0;
		}
		if(N == 4){
			res.push_back(2);
			res.push_back(3);
			res.push_back(4);
			res.push_back(9);
			N = 0;
		}
		if(5 <= N && N <= 6){
			res.push_back(2);
			res.push_back(3);
			res.push_back(4);
			res.push_back(6);
			res.push_back(9);
			if(N == 6) res.push_back(12);
			N = 0;
		}
		while(N > 0){
			int p = min(8, N);
			int arr[] = {3, 9, 8, 10, 2, 4, 6, 12};
			int start = 8 - (p+1)/2 * 2;
			for(int i=0;i<p;i++) res.push_back(base + arr[i + start]);
			base += 12;
			N -= p;
		}
		cout << res[0];
		for(int i=1;i<res.size();i++) cout << " " << res[i];
		cout << endl;
	}
}
