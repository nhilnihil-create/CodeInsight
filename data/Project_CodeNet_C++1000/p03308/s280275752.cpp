#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int maxv=0,minv=2e9,tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        maxv=max(maxv,tmp);
        minv=min(minv,tmp);
    }
    cout<<maxv-minv<<endl;
    return 0;
}