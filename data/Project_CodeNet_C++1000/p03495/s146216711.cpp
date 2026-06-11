#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
int n, k;
unordered_map<int, int> mp;
int main() {
	cin >> n >> k;
  	int a;
  	for (int i = 0; i < n; i++) {
    	cin >> a;
      	if (mp.find(a) == mp.end()) {
          mp[a] = 1;
        } else {
          mp[a] = mp[a] + 1;
        }
    }
  	int nums[mp.size()];
  	int i = 0;
  	for (pair<int, int> element : mp) {
      	nums[i++] = element.second;
      	
    }
  	sort(nums, nums+mp.size());
  	int k2 = 0;
  	if (mp.size() < k) {
    	cout << 0 << endl;
      	return 0;
    }
  	for (int i = 0; i < mp.size()-k; i++) {
     	k2 += nums[i];
    }
  	cout << k2 << endl;
 	return 0;
}
