#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long int ll;
template<typename T> T changeMax(T& a, T b){if(a < b)a = b;return 0;}

int main()
{
    int a, b;
    cin >> a >> b;
    if(a % b == 0){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }
}