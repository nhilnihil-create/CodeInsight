#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n;

    cin>>n;

    if(n%2){
        cout<<n*2<<endl;
    }else{
        cout<<n<<endl;
    }
}