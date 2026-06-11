#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<string>
#define INF 10009310000
using namespace std;
map<char,int> ele;
string x,y;
int n;
long long lucas[88];
int main(){
    scanf("%d",&n);
    lucas[0]=2;
    lucas[1]=1;
    for(int i=2;i<=n;i++)
        lucas[i]=lucas[i-1]+lucas[i-2];
    printf("%lld",lucas[n]);
}