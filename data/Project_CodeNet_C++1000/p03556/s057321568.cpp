#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i*i<=n){
        i++;
    }
    int ans=(i-1)*(i-1);
    cout<<ans<<endl;
}