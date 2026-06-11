#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x,y;
    x=c-a,y=d-b;
    printf("%d %d %d %d\n",c-y,d+x,a-y,b+x);
}   
