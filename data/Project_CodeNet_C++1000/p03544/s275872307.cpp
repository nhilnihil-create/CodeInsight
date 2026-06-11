#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int64_t Lucas_0 = 2, Lucas_1 = 1, Lucas;

    int index = 1;

    while(index != N){
        Lucas = Lucas_1 + Lucas_0;
        Lucas_0 = Lucas_1;
        Lucas_1 = Lucas;
        index++;
    }
  
	if(N == 1) cout << Lucas_1 << endl;
    else cout << Lucas << endl;
}
