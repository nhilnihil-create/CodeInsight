#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N=200000+10;
char s[N];
vector<int> g[N];
void prt(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        printf("%d %d\n", u,v);
        prt(v,u);
    }
}
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<n;i++) if(s[i]!=s[n-i]) return !printf("-1\n");
    if(s[1]=='0'||s[n]=='1') return !printf("-1\n");
    int now=1, top=1;
    for(int i=1,j=i;i<=n;i=j){
        if(s[i]=='1'){
            if (i!=1){ 
                while(now+1<=i) {
                    //printf("add %d %d\n", now+1, top);
                    g[now+1].push_back(top); 
                    g[top].push_back(now+1);
                    ++now;
                }
            }
            while(j<=n&&s[i]==s[j]) {
                ++j; 
                //printf("addd %d %d\n", now+1, top);
                g[now+1].push_back(top), g[top].push_back(now+1); ++now; top=now;
            }
        } else {
            ++j;
        }
    }
    prt(top,top);
}




