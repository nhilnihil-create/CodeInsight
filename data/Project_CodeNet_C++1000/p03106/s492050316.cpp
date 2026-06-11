#include <iostream>
#include<algorithm> 
#include <numeric>
#include <vector>
using namespace std;
int main(void){
    int a,b,k;
    cin>>a>>b>>k;
    vector<int> v;
    for (int i = 1; i<=a; i++){
        if (a%i==0 && b%i==0){
            v.push_back(i);
        }
    }
    reverse(v.begin(), v.end());
    cout<<v.at(k-1);
    
}
