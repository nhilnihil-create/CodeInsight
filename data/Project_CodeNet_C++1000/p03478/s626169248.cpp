#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for(int i = 1; i < n+1; i++){
		char* num = (char*)calloc(10, sizeof(char));
		snprintf(num, 10,"%d", i);
		int sum = 0;
		while(*num != '\0'){
			sum += *num - 48;
			num++;
		}
		if(sum >= a && sum <= b) {
			ans += i;
		}
	}
	cout << ans << endl;
}
