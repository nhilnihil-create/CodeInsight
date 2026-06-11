#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
	int64_t a = 2;
    int64_t b = 1;
    int64_t c = a + b;
    if(N == 1){
    	cout << 1 << endl;
    }else if(N == 2){
    	cout << 3 << endl;
    }else{
    	for(int i = 0; i < N - 2; i++){
            a = b;
            b = c;
            c = a + b;
        }
        cout << c << endl;
    }
}