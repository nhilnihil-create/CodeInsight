#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;

int SUM(int m){
    
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        sum += i;
    }
    return sum;
} 

int main() {
    int a,b; cin >> a >> b;
    
    print(SUM(b - a) - b);
}
