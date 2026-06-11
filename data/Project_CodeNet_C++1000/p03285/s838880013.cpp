#include <bits/stdc++.h>
using namespace std;
#define FOR(I,A,B)          for(int I=A; I<B; I++)
#define LL                  long long
#define PSI                 pair<string,int>
#define MOD                 1000000007
#define MAX                 1000005
#define READ(A)             freopen(A,"r",stdin)

int main() {
    //READ("input.txt");
    int N;
    bool B=false;
    scanf("%d",&N);
    FOR(I,0,N/4+1){
        FOR(J,0,N/7+1){
            if(4*I+7*J==N)B=true;
        }
    }
    if(B)printf("Yes\n");
    else printf("No\n");
}
