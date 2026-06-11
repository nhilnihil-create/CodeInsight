#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int diff = b - a;
    if(diff % 2 == 0) puts("Alice");
    else puts("Borys");
    return 0;
}