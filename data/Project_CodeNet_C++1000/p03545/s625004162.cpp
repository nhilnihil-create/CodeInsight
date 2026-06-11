#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(4);
    for(int i=3;i>=0;i--){
        a[i]=n%10;
        n/=10;
    }
    vector<char> op(3);
    int sum=0;
    for(int bit=0;bit<(1<<3);bit++){
        sum=a[0];
        rep(i,3){
            if(bit & (1<<i)){
                op[i]='+';
                sum+=a[i+1];
            }
            else{
                op[i]='-';
                sum-=a[i+1];
            }
        }
        if(sum==7) break;
    }
    rep(i,3){
        cout<<a[i]<<op[i];
    }
    cout<<a[3]<<"=7"<<"\n";
    return 0;
}