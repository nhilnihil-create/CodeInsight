#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int x,y;
    cin>>x>>y;
    if (x%y==0) {
        cout<<-1<<endl;
    } else {
        for (long long int i=1;x*i<=1000000000000000000;i++) {
            if (x*i%y!=0) {
                cout<<x*i<<endl;
                return 0;
            }
        }
    }
}