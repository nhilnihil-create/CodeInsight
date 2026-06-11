#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  	int N;
  	cin >> N;
  	vector<int> a(N);
  	for (int i = 0; i < N; i++) cin >> a[i];
  	cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << endl;
}