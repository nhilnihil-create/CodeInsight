#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b){
    if(a < b){
        return gcd(b,a);
    }
    else if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }

}


int main()
{
    LL T,A,B,C,D;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>A>>B>>C>>D;
        LL g = gcd(B,D);
        bool check = true;
        if(A < B){
            check = false;
        }
        if(D < B){
            check = false;
        }
        if(C < (A-B)%g + (B-g)){
            check = false;
        }
        if(check)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }

    return 0;
}
