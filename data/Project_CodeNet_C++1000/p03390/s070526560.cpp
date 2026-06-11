#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long sum = a*b;
        long long ss = (long long)sqrt(sum);
        if(a==b||abs(a-b)==1){
            a  = min(a,b);
            cout<<2*a-2<<endl;
        }else{
            if(ss*ss==a*b) ss--;
            if(ss*(ss+1)>=a*b){
                cout<<2*ss-2<<endl;
            }else{
                cout<<2*ss-1<<endl;
            }
        }
    }
}
