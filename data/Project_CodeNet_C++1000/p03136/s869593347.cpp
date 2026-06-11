#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum=0,maxv=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
        maxv=max(maxv,a);
    }
    if(sum-maxv>maxv)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}