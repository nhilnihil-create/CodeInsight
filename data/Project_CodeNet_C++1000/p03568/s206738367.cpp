#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int e=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0) e++;
    }
    cout<<pow(3,n)-pow(2,e)<<endl;
}