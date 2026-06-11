#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int temp = 1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a % 2 == 0){
            temp *= 2;
        }
    }
    cout << pow(3, n) - temp << endl;
    return 0;
}