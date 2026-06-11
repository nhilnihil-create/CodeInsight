#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long ans;
    long long tmp1=1,tmp2=1;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        tmp1*=3;
        if(a%2==0){
            tmp2*=2;
        }
    }
    cout<<tmp1-tmp2<<endl;
    return 0;
}