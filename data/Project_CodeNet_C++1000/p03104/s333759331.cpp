#include <bits/stdc++.h>
using namespace std;

long long solve(long long a){
    if (a <= 0) return 0;
    if(a%2 == 1 && ((a+1)/2)%2 == 0)
        return 0;
    if(a%2 == 1 && ((a+1)/2)%2 == 1)
        return 1;
    return a^solve(a-1);
}

int main(){
    long long a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    cout << (solve(a-1)^solve(b)) << "\n";
}
