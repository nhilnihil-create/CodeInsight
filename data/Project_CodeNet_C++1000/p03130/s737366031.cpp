#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cfenv>
using ll = unsigned long long;
using namespace std;

int main(){
    vector<int> vec(4);
    for(int i=0;i<3;i++){
        int a,b;cin >> a >> b;
        a--;b--;
        vec[a]++;
        vec[b]++;
    }
    int c=0;
    for(int i=0;i<4;i++){
        if(vec[i]%2==1){
            c++;
            
        }
        if(c>=3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}