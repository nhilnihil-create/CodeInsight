#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    while(cin>>n){
        if(n==3){
            cout<<"180"<<endl;
        }
        else cout<<((2*n-4)*90)<<endl;
    }
    return 0;
}
