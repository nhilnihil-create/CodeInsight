#include <iostream>
using namespace std;

int f_func(int x){
    int ans=0;
    while(x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    
    if(n%f_func(n)==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
