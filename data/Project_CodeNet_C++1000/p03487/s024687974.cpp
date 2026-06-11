#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	unordered_map<int, int> map;
  	int n, a, c;
  	cin >> n;
  	for (int i = 0; i < n; i++) {
    	cin >> a;
      	if (map.find(a) == map.end()) {
          	c = 1;
        } else {
          c = map[a] + 1;
        }
        map[a] = c;
    }
  	int key, val;
  	int ans = 0;
  	for (pair<int, int> element: map) {
    	key = element.first;
      	val = element.second;
      	if (val > key) {
        	ans += val - key;
        } else if(val == key) {
         	ans += 0; 
        }else {
          	ans += val;
        }
    }
  	cout << ans;
}