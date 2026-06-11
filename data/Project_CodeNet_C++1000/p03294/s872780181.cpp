#include <iostream>
#include<vector>
using namespace std;

int main(){
    long long N,n,num(1),ans(0);
    cin >> N;
    vector<long long> v;
    for(int j=0;j<N;j++){
        cin >> n;
        v.push_back(n);
    }
    for(int j=0;j<N;j++){
        ans+=v[j]-1;
    }
    cout << ans;
}