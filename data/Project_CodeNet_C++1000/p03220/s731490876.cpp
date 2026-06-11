#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,t,a;
    cin>>n;
    cin>>t>>a;
    vector<int>h(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    float result;
    int index=0;
    bool inside=true;
    for(int i=0;i<n;i++)
    {
        float temp;
        temp=t*1.0-h[i]*0.006;
        if(inside||abs(temp-a)<abs(result-a)){
            result=temp;
            index=i+1;
            inside=false;
        }
    }
    cout<<index;
}