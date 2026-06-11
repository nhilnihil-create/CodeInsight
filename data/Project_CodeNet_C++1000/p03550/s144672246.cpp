#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
using ll = long long ;
using namespace std;
int main(){
    int n,z,w;
    cin >> n >> z >> w;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }
   // cout<<vec[n-1]-vec[n-2]<<endl;
   if(n==1)cout<<abs(vec[0]-w);
   else{
    cout<<max(abs(vec[n-2]-vec[n-1]),abs(vec[n-1]-w))<<endl;
}
}
