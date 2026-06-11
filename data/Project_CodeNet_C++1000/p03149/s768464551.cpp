#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a==1 || b==1 || c==1 || d==1) {
        if (a==4 || b==4 || c==4 || d==4) {
            if (a==7 || b==7 || c==7 || d==7) {
                if (a==9 || b==9 || c==9 || d==9) {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}