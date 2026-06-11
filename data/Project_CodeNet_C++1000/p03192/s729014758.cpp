#include <iostream>

using namespace std;

int main(){
    char n[100];
    cin>>n;
    int ans=0;
    for (int i=0; i<4; i++) {
        if(n[i]=='2'){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
