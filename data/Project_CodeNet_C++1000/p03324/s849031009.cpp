#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int d,n;
    cin>>d>>n;
    int ans=1;
    for(int i=0;i<d;i++){
        ans*=100;
    }
    if(n==100)cout<<ans*(n+1)<<endl;
    else cout<<ans*n<<endl;
    return 0;
}