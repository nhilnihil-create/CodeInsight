#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repJ(j, n) for (int j = 0; j <(int)(n); j++)

string a[3];
int main(){
    rep(i, 3){
            cin >> a[i];
    }
    cout << a[0][0] <<a[1][1] << a[2][2] << endl;
}