#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%111==0)cout<<n<<endl;
    else cout<<((n/111)+1)*111<<endl;

    return 0;
}