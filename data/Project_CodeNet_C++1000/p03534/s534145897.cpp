#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
#define LL long long
#define mp make_pair
#define fr first
#define sc second
#define pb push_back
const int N=100010;
char s[N];
int c[10];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n;
    scanf("%s",s+1);n=strlen(s+1);
    for (i=1;i<=n;i++) c[s[i]-'a']++;
    sort(c,c+3);
    if (c[2]-c[0]<=1) puts("YES");
     else puts("NO");

    return 0;
}
