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
int vis[5];
int main () {
    int n;
    scanf("%d",&n);
    string a,b,c;
    while(cin>>a>>b>>c){
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]&&a[i]==c[i]){
                ;
            }
            else if(a[i]==b[i]||a[i]==c[i]||b[i]==c[i]){
                ans++;
            }else ans+=2;
        }
        printf("%d\n",ans);
    }
   //while(1)getchar();
    return 0;
}
