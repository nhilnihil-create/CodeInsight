#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    for(int i = n; i > 0; i--){
        for(long long int j = sqrt(n); j > 0; j--){
            if(i == j * j){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}