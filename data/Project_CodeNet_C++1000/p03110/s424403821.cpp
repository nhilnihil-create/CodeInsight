#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double> x(n);
    vector<string> u(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>u[i];
    }
    double sum=0;
    for(int i=0;i<n;i++){
        if("JPY"==u[i]){
            sum+=x[i];
        }else{
            sum+=380000*x[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}