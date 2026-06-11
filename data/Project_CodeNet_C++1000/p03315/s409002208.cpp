#include <iostream>

using namespace std;

int main(){
    char c;
    int ans=0;
    for(int i=0;i<4;i++){
        cin>>c;
        if(c=='+')
            ans++;
        else
            ans--;
    }
    cout<<ans<<endl;

    return 0;
}