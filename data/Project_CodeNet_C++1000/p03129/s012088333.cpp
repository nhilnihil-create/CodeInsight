#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <set>
using namespace std;
#define maxn 100000+5
typedef long long int ll;
const double INF = 1e20;
const double pi = acos (-1.0);
int main () {
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        int coun=0;
        for(int i=1;i<=n;i+=2){
            coun++;
        }
        if(coun>=k)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
