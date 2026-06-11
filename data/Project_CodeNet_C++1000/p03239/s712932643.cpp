#include<bits/stdc++.h>
using namespace std;

#define REPN(i, n) for(int (i) = 0; (i)<n; (i)++)

const int MAX (1010);
const int oo (2000000010);

int cs[MAX], ts[MAX];

void solve(int n, int t){
    int ans = oo;

    //Escolhe dentre as rotas, o maior custo cujo tempo é menor ou igual a T
    REPN(i, n)
        if(ts[i] <= t)
            ans = min(ans, cs[i]);

    if(ans==oo)
        cout<<"TLE\n";
    else
        cout<<ans<<endl;
}

int main(){
    int n,t;
    cin>>n>>t;

    REPN(i,n)
        cin>>cs[i]>>ts[i];

    solve(n, t);

    return 0;
}