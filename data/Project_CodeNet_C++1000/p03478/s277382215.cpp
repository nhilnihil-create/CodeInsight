#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,A,B;
    cin >> N >> A >> B;

    int ans=0;

    for(int i=1;i<N+1;i++){
        int w=0;
        int n=i;
        while(n!=0){
            w+=n%10;
            n=n/10;
        }

        if(A<=w&&w<=B){
            ans+=i;
        }

    }

    cout << ans << endl;
}