#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    long long n;
    cin>>n;
    long long temp = n;
    int units = n % 10;
    int digits = 0;
    int sum = 0;
    int msb;
    while(n > 0) {
    	msb = n % 10;
    	n /= 10;
    	digits++; 
    }
    digits--;
    if(units == 9)
    	sum += (digits * 9) + msb;
    else if(digits == 0)
    	sum += msb;
    else
    	sum += (digits * 9) + --msb;

    cout << sum;


	return 0;		
}
