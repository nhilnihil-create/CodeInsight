#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

char S[10];
ll i, j, k;
int main(){
    scanf("%s", S);
    j = 0;
    fornum(i,0,4){
        if(S[i]=='+'){
            ++j;
        }else{
            --j;
        }
    }
    printf("%lld\n", j);
    return 0;
}