#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int sum=0;
    for(int i=0;i<n;i++){
    cin >>vec.at(i);
}
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for(int i=1;i<n;i++){
    sum+=vec.at(i);
    }
    sum += vec.at(0)/2;
    cout << sum <<endl;
}