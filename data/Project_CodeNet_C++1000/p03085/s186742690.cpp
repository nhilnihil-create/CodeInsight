#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    char n;
    cin >> n;
    if(n == 'A') cout << 'T' << endl;
    else if(n == 'T') cout << 'A' << endl;
    else if(n == 'G') cout << 'C' << endl;
    else cout << 'G' << endl;
}