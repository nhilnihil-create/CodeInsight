#include <iostream>
#include <map>
using namespace std;

map <long long , long long> frequency;

int main(){
  int n;
  cin >> n;

  long long sum = 0;
  long long num = 0;
  long long ans = 0; 

	frequency[0] = 1; 
  for(int i = 0; i < n; i++){
    cin >> num;
		sum += num; // Frequency index
		ans += frequency[sum];
		frequency[sum]++;
  }
	cout << ans << endl;
	exit(0);
}