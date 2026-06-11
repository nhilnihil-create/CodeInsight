#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

void solve_77B(){
    int n;
    cin >> n;
    int max = 0;
    for(int i = 0; i*i <= n; i++){
        max = i*i;
    }
    cout << max << endl;
}

int main(void){
    solve_77B();
    
    return 0;
}