#include <iostream>
using namespace std;
int main(void){
    int n,i,s=0,m=0,a;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a;
        m = max(a,m);
        s+=a; 
    }
    if(m<s-m) cout << "Yes";
    else cout << "No";
}