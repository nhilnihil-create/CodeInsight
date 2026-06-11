#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a.at(i);
        // cout<<a.at(i)<<endl;
    }
    sort(a.begin(),a.end());
  	reverse(a.begin(),a.end());
    // for (int i=0;i<n;i++){
    //     cout<<a.at(i)<<endl;
    // }
    int alice=0,bob=0;
    for (int i=0 ;i<n;i+=2){
        bob+=a.at(i);
        // cout<<bob<<endl;
    }
    for (int i=1; i<n;i+=2){
        alice+=a.at(i);
        // cout<<alice<<endl;
    }
    cout<<max(bob-alice,alice-bob)<<endl;
    
    return 0;
}
