#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    int a,b;
    cin>>a>>b;
    int a2,b2,ab;
    a2=a*2-1;
    b2=b*2-1;
    ab=a+b;
    if(a2>=b2 && a2>=ab){
        cout<<a2<<endl;
    }else if(b2>=a2 && b2>=ab){
        cout<<b2<<endl;
    }else if(ab>=a2 && ab>=b2){
        cout<<ab<<endl;
    }
    
    return 0;
}
