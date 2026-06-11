#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    string c1, c2;
    int ans1=0, ans0=0;
    for(int i=0; i<s.size(); i++){
        if(i%2 == 0){
            if(s[i] == '0'){
                ans1++;
            }else{
                ans0++;
            }
        }else{
            if(s[i] == '0'){
                ans0++;
            }else{
                ans1++;
            }
        }
    }

    cout<<min(ans0, ans1)<<endl;
    return 0;
}