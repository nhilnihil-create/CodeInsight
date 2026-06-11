#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=i;
        int num=0;
        while(x>0){
            num+=x%10;
            x/=10;
        }
        if(num>=a&&num<=b)ans+=i;
    }
    cout<<ans<<endl;
    return 0;
}