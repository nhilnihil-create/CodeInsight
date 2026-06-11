#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    vector<int>a(1000001);
    int k;
    cin>>k;
    for(int i=1;i<=1000001;i++){
        a[k]++;
        if(a[k]>1){
            cout<<i<<endl;
            break;
        }else{
            if(k%2==0)k=k/2;
            else k=3*k+1;
        }
    }
    return 0;
}