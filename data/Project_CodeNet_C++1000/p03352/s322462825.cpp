#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans=1;
	for (int i=2; i<=N; i++){
	    int power=i*i;
	    for (int j=2; ; j++){
	        if (power>N) break;
	        ans=max(ans, power);
	        power*=i;
	    }
	}
	cout << ans << endl;
}
