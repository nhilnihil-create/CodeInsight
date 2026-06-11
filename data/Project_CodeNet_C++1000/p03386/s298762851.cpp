#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long a,b,k;
    cin>>a>>b>>k;
    f(i,a,b+1){
        if(i-a+1<=k||b-k+1<=i){
            cout<<i<<endl;
        }
    }
    return 0;
}
