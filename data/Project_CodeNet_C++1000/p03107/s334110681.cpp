#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin>>s;

    int c0 = 0, c1 = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            c0++;
        }else if(s[i]=='1'){
            c1++;
        }
    }

    cout<<min(c0,c1)*2<<endl;
    return 0;    
}