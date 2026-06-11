#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> array(m);
    for(int i=0;i<m;i++){
        cin >> array.at(i);
    }
    sort(array.begin(),array.end());
    vector<int> dev(m-1);
    for(int i=0;i<array.size()-1;i++){
        dev.at(i) = array.at(i+1) - array.at(i);
    }
    sort(dev.begin(),dev.end());
    int sum = 0;
    if(n < m){
        int k = dev.size();
        for(int i=k-n;i>=0;i--){
            //cout << i << endl;
            sum += dev.at(i);
        }
    }
    cout << sum << endl;
}