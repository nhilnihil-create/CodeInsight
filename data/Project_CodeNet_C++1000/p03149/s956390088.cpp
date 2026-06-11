#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int input[4];

bool elem(int n){
    if(input[0] == n || input[1] == n || input[2] == n || input[3] == n) return true;
    else return false;
}

int main(void){
    cin >> input[0] >> input[1] >> input[2] >> input[3];
    if(elem(1) & elem(9) & elem(7) & elem(4)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}