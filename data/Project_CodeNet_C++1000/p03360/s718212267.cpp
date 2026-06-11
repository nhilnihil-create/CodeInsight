#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    vector<int> abc(3);
    vector<int> sumabc(3);
    for(int i=0;i<abc.size();i++){
        cin>>abc[i];
    }
    sort(abc.begin(),abc.end());
    int k;
    cin>>k;
    int sum=0;
    for(int i=0;i<abc.size()-1;i++){
        sum+=abc[i];
    }
    
    cout<<sum+pow(2,k)*abc.back()<<endl;
    return 0;
}