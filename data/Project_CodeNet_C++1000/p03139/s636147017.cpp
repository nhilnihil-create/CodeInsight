#include <iostream>

using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int maxi = min(a,b);
       cout<<maxi<<endl;
    if(n<=a+b){
        int mini = a+b-n;
        cout<<mini<<endl;
    }else{
        int mini = 0;
        cout<<mini<<endl;
    }
    return 0;
}