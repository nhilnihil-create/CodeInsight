#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >>a>>b>>c;
    int buy=-1;
    if(a*c<=b){
        cout << c << endl;
        return 0;
    }
    else{
        while(b>=0){
            buy += 1;
            b -= a;
        }
        cout << buy << endl;
        return 0;
    }
}