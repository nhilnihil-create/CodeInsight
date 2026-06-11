#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    int ans=pow(3,n);
    int yo=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            yo *= 2;
        }
    }
    ans -= yo;
    cout<<ans<<endl;
}