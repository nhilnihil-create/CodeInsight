#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int lim =(n%2? n/2+1:n/2);
    cout<<(lim<k?"NO":"YES");
}