#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, max;
    cin >> N;
    max = (N/4)+1;
    bool Ans = 0;
    for (int i=0; i<=max; i++){
      	for (int j=0; j<=max-i; j++){
          	if ((4*i+7*j)==N){
                Ans = 1;
                break;
            }
        }
        if (Ans == 1) break;
    }
    if (Ans == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
