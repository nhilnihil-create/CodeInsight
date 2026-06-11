#include<bits/stdc++.h>
using namespace std;

int main(){
    string A,B,C;
    cin>>A>>B>>C;
    
    int ans = max({ stoi(A+B)+stoi(C),
                    stoi(B+A)+stoi(C),
                    stoi(B+C)+stoi(A),
                    stoi(C+B)+stoi(A),
                    stoi(C+A)+stoi(B),
                    stoi(A+C)+stoi(B)});

    cout<<ans<<endl;
    return 0;
}