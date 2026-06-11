#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pp;

int N;
const int MAX_N = 55;
int a[MAX_N];
vector<pp> s;

int main(){
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> a[i];
	}

	int m = min_element(a+1,a+N+1)-a;
	int M = max_element(a+1,a+N+1)-a;

	if(a[M]+a[m] >= 0){
		for(int i=1;i<=N;i++){
			if(a[i]<0){
				s.push_back({M,i});
			}
		}
		for(int i=1;i<=N-1;i++){
			s.push_back({i,i+1});
		}
	}else{
		for(int i=1;i<=N;i++){
			if(a[i]>0){
				s.push_back({m,i});
			}
		}
		for(int i=N;i>1;i--){
			s.push_back({i,i-1});
		}
	}

	cout << s.size() << endl;
	for(auto& i:s){
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}