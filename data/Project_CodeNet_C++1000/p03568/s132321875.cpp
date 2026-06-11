#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    int t=1,c=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        t*=3;
        if(a[i]%2==0) c*=2;
    }
    
    cout<<t-c<<endl;
}