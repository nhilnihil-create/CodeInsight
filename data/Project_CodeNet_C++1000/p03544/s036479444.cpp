#include <bits/stdc++.h>
using namespace std;

int main() {
    int i=0;
    int n;
    cin>>n;
    vector<long long> data(90);
    data.at(0)=2;
    data.at(1)=1;
    for(i=0;i<n-1;i++){
        data.at(i+2)=data.at(i)+data.at(i+1);
    }
    cout<<data.at(i+1)<<endl;
}
