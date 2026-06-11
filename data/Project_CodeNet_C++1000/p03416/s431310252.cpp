#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int A,B;
    cin>>A>>B;
    int count=0;
    int tmp,t;
    for(int i=A; i<=B; i++){
        tmp= i;
        t=0;
        while(tmp!=0){
            t=(t*10)+(tmp%10);
            tmp/=10;
        }
        if(A==t){
            count++;
        }
        A++;
    }
    cout<<count<<endl;;
}