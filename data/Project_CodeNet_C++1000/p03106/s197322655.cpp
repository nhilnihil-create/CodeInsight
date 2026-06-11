#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    if(a>b)swap(a,b);
    int cnt=0;
    int end=0;
    int ans;
    int n[100];
    for(int i=1;i<=a;i++){
        if(a%i==0&&b%i==0){
            cnt++;
            n[cnt]=i;
        }
    }
    cout<<n[cnt-k+1]<<endl;
    return 0;
}