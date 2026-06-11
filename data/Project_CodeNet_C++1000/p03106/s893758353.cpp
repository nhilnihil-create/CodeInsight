#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int kfactor(int a,int k){
    vector<int>v1,v2;
    for(int i=1;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            v1.push_back(i);
            v2.push_back(a/i);
        }
    }
    if(k<=v2.size())
    {
        k--;
        return v2[k];
    }
    if(sqrt(a)*sqrt(a)==a){
        k++;
    }
    k-=v2.size();
    k=v1.size()-k;
    return v1[k];
}

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    int hcf=gcd(a,b);
    cout<<kfactor(hcf,k);
}