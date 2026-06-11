#include<iostream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
    int n;
    int a;
    int sum=0;
    cin>>n;
    rep(i,n){
        cin>>a;
        sum+=(a-1);
    }
    cout<<sum;
}