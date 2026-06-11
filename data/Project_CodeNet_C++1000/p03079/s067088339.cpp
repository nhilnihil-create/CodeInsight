#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<cmath>

using namespace std;

typedef long long ll;
#define INF 1000000007

int main(){
    int a, b, c;
    cin >> a >> b >>c;

    if(a == b && b == c && c == a) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}
