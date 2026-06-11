#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main (){
    int n;
    cin >> n;
	for(int i = 0; i <= n; i += 4){
        if((n - i) % 7 == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}