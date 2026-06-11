#include<iostream>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    int minv=2000;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        minv=min(minv,a[i]);
    }
    cout<<n+(x-sum)/minv<<endl;
    return 0;
}