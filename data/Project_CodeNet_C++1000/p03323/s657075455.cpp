#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll A, B;
ll i, j, k;
int main(){
    scanf("%lld%lld", &A, &B);
    if(A<=8&&B<=8){
        printf("Yay!\n");
    }else{
        printf(":(\n");
    }
    return 0;
}