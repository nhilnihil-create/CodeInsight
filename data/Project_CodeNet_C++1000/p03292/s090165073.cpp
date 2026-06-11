#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    vector<int>a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(),a.end(),greater<>());
    cout<<a[0]-a[2]<<endl;

    return 0;
}