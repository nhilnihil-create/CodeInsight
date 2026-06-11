#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
typedef pair<int,int> P;
#define mod 1000000007

int main(){
    int a,b;
    cin >> a >> b;
    if(b>=a){
        cout << a << endl;
        return 0;
    }
    else{
        cout << a-1 << endl;
        return 0;
    }
}