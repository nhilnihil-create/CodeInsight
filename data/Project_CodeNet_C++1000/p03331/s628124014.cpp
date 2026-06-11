#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    int ans=1e9;
    for(int i=1;i<=n/2;i++){
        sum=0;
        int x=i;
        int j=n-x;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        while(j>0){
            sum+=j%10;
            j/=10;
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}