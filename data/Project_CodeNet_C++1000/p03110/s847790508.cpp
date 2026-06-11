#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    double u;
    double sum=0;
    for(int i=0;i<n;i++){
        cin>>u>>s;
        if(s=="JPY")sum+=u;
        else sum+=u*380000.0;
    }
    cout<<sum<<endl;
    return 0;
}