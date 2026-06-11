# include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, currentSize, a[N];
vector < int > order;
void erase(int index, int &arraySize){
	for(int i = index + 1; i <= arraySize; ++i){
		swap(a[i], a[i - 1]);
	}
	arraySize--;
}
int main(){
	cin >> n;
	currentSize = n;
	for(int i = 1; i <= n; ++i)cin >> a[i];
	while(currentSize >= 1){
		int index = -1, mx = 0;
		for(int i = 1; i <= currentSize; ++i){
			if(a[i] == i){
				if(mx < a[i]){
					mx = a[i];
					index = i;
				}
			}
		}
		if(index == -1){
			cout << "-1\n";
			return 0;
		}
		order.push_back(index);
		erase(index, currentSize);
	}
	reverse(order.begin(), order.end());
	for(int i = 0; i < order.size(); ++i)cout << order[i] << '\n';
}