#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
    cin >> N;
    string ans = "No";
    int a = N/100000000;
    int b = N/10000000 - a*10;
    int c = N/1000000 - a*100 - b*10;
    int d = N/100000 - a*1000 - b*100 - c*10;
    int e = N/10000 -a*10000 - b*1000 - c*100 - d*10;
    int f = N/1000 - a*100000 - b*10000 - c*1000 - d*100 - e*10;
    int g = N/100 - a*1000000 - b*100000 - c*10000 - d*1000 - e*100 - f*10;
    int h = N/10 - a*10000000 - b*1000000 - c*100000 - d*10000 - e*1000 - f*100 - g*10;
    int i = N%10;
    int sum = a + b + c + d + e + f + g + h + i;
    if(N%sum == 0){
      ans = "Yes";
    }
    cout << ans << endl;
}