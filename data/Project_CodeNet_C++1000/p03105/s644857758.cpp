#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
const ll N = 1e2+5;

int ans[N];
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",min(b/a,c));
    return 0;
}
