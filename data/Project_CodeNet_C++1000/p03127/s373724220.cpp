#include<iostream>
#include<vector>
using namespace std;

int gcd(int x,int y){
    return y ? gcd(y,x%y) : x;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int ans=0;
    for(int i=0;i<n;i++){
        ans=gcd(ans,a[i]);
    }
    cout<<ans<<endl;
}