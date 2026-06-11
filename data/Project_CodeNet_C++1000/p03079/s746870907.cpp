#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int a,b,c;

int main(void){
    scanf("%d%d%d",&a,&b,&c);
    printf("%s\n",a==b&&b==c?"Yes":"No");
    return 0;
}