#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+2,0);
    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }
    int sum=0;
    
    for(int i=0;i<n+1;i++){
        sum+=abs(a[i+1]-a[i]);
    }
    for(int i=0;i<n;i++){
        cout<<sum-abs(a[i+2]-a[i+1])-abs(a[i+1]-a[i])+abs(a[i+2]-a[i]) <<endl;
    }
    return 0;
}