#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int N;
	int cnt;
	int flag;
	cin >> N;
	vector<int> vec(N);

	for(int i=0;i<N;i++) {
		cin >> vec.at(i);
	}
	
	cnt=0;
	while(true) {
		flag  = 0;
		for(int i=0;i<N;i++){
			if(vec.at(i)%2==0 && vec.at(i)!=0){
				vec.at(i) /= 2;
				flag++;
			}
		}
		
		if(flag == N) {
			cnt++;
		} else {
			break;
		}
	}
	cout << cnt << endl;
}