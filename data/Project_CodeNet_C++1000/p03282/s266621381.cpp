#include <bits/stdc++.h>
using namespace std;

//106_C

string S;
int k;

int main(){
    cin>>S;
    cin>>k;
    for(int i=0;i<k;i++){
        if(S[i]-'0'>1){
            cout<<S[i]<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
}