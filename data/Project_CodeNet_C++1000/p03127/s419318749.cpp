#include<iostream>
#include<vector>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int result=v[0];
    for(int i=0;i<n;i++)
    {
        result=gcd(result,v[i]);
    }
    cout<<result<<endl;
}