#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b,c,k;
    cin>>a>>b>>c>>k;
    if (k%2==0) {
        long long int ans=a-b;
        if (abs(a-b)>1000000000000000000) {
            cout<<"Unfair"<<endl;
        } else {
            cout<<ans<<endl;
        }
    } else {
        long long int ans=-1*(a-b);
        if (abs(a-b)>1000000000000000000) {
            cout<<"Unfair"<<endl;
        } else {
            cout<<ans<<endl;
        }
    }
}