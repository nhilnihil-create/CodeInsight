#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;

int main(void){
    int a,b;
    cin >> a >> b;
    int A = a+b;
    int B = a-b;
    int C = a*b;
    int max = A;
    if(max<B) max = B;
    if(max<C) max = C;
    cout << max << endl;

    
    return 0;
}
