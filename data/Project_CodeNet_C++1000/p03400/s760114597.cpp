#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,d,x;
    cin>>n>>d>>x;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        x+=(d-1)/a+1;
    }
    cout<<x<<endl;
    return 0;
}