#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec(3);
    for(int i=0;i<3;i++){
        cin>>vec.at(i);
    }
    sort(vec.begin(),vec.end());
    int k; cin>>k;
    for(int i=0;i<k;i++){
        vec.at(2)*=2;
    }
    cout<<vec.at(0)+vec.at(1)+vec.at(2)<<endl;
}