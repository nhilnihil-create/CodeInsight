#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    ll K,A,B; cin>>K>>A>>B;
    ll biske=1;
    while(K>0){
        if(biske<A){
            biske++;
            K--;
        }
        else{
            if(K>1 && A+1<B){
                biske+=(B-A);
                K=K-2;
            }
            else{
                biske++;
                K--;
            }
        }
    }
    cout<<biske;
    return 0;
}