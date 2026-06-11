#include <bits/stdc++.h>
using namespace std;

int main() {
    int  t,s,k;
    cin >> t >> s >> k;
    for(int i=0;i<k;i++){
        if(i%2==0){
            s+=t/2;
            t/=2;
        }
        else{
            t+=s/2;
            s/=2;
        }
    }
    cout << t << " " <<  s << endl;
}