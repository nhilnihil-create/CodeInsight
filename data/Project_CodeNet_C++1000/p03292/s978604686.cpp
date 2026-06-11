#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    vector<int> v(3);
    for(int i=0;i<3;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int cost=0;
    for(int i=0;i<2;i++){
        cost+=v[i+1]-v[i];
    }
    cout<<cost<<endl;
    return 0;
}