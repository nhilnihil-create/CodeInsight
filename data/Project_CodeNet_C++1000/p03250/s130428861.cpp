#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    int n;
    vector<int>a(1000000);
    vector<int>b(1000000);
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),std::greater<>());
    cout<<10*a[0]+a[1]+a[2]<<endl;
    
    return 0;
}