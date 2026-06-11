#include <bits/stdc++.h>
using namespace std;

int main(void){
    string N;cin>>N;
    int ans=0;
    int check=0;
    if(N.size()==1){
        cout<<N[0]-'0'<<endl;
        return 0;
    }
    else{
        for(int i=1;i<N.size();i++){
            if(N[i]!='9'){
                break;
            }
            check++;
        }
        if(check==N.size()-1){
            ans+=N[0]-'0';
            ans+=9*(N.size()-1);
            cout<<ans<<endl;
            return 0;
        }
        else{
            ans+=9*(N.size()-1);
            ans+=N[0]-'1';
            cout<<ans<<endl;
            return 0;
        }
    }
}