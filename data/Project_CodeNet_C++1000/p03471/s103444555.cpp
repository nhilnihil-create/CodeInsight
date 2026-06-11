#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i < n; i++)
using namespace std;
using ll = long long;
int main(void){
    int n,y;
    cin>>n>>y;
    int a,b,c;
    for(a=0;a<=n;a++){
        for(b=0;b<=n;b++){
            c=n-a-b;
            int money=10000*a+5000*b+1000*c;
            if(money==y&&c>=0){
                cout<<a<<" "<<b<<" "<<c<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<endl;

    return 0;
}