#include <iostream>
#include <map>
#include <cmath>
using namespace std;

long long frequencyCount[100005];
/* Index = ascii value of s[i]
	Value at i-th index = count of that character */

void findFrequency(long long n , string s){
	long long ans = 1; 
	long long temp = pow(10,9) + 7;
	frequencyCount[(long long)s[0]] = 1;

	for(long long i = 1; i < n; i++){
		frequencyCount[(long long)s[i]]++;
	}
	for(long long i = (int)'a'; i <= (int)'z'; i++){
		frequencyCount[i]++;
		ans*=frequencyCount[i];
		ans = ans % temp;
	}
	ans--; 
	cout << ans << endl; 
}

int main(){
	long long n;
	string s;
	cin >> n >> s; 

	findFrequency(n , s);
}