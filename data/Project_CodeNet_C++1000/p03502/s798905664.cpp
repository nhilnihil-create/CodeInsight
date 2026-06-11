#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    int temp = n;
    string s = to_string(n);
    
    int len = s.length(), sum=0;
    
    for(int i=0; i<len; i++){
        int d = n%10;
        sum += d;
        n = n/10;
        
    }
    
    if(temp%sum==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    
    
	return 0;
}
