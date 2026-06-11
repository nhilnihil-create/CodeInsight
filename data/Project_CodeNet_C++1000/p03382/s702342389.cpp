#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5+15;

int ar[N];
int main(){

    //freopen("input.txt","r",stdin);

    int n;cin>>n;
    int maxi = 0;
    for(int i=0;i<n;++i){
        scanf("%d",&ar[i]);
        maxi = max(maxi,ar[i]);
    }
    int cand = maxi;
    int m = (maxi+1)/2;
    for(int i=0;i<n;++i){
        if( abs(cand-m)>= abs(ar[i]-m))
            cand = ar[i];
    }
    printf("%d %d\n",maxi,cand);
    return 0;
}