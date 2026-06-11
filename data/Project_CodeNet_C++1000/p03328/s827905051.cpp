#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int a,b;
    cin >> a >> b;
    int x = b-a;
    int s = (1 + (b-a)) * (b - a);
    s /= 2;
    cout << s - b << endl;
}