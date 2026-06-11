#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x=n;
    int f=0;
    while(x>0){
        f+=x%10;
        x/=10;
    }
    if(n%f==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}