#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    char a;
    cin >> a;
    if(a == 'A') cout << 'T' << endl;
    else if(a == 'T') cout << 'A' << endl;
    else if(a == 'G') cout << 'C' << endl;
    else if(a == 'C') cout << 'G' << endl;
}