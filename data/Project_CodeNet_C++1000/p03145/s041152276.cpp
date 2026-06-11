#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    double s = (a + b + c) / 2;
    double sum = s * (s - a) * (s - b) * (s - c);
    cout << sqrt(sum) << endl;

}
