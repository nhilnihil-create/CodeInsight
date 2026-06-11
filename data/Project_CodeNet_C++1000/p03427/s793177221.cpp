#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin>>S;
    long long  sum=0;
    if(S.size()==1){
        cout <<S.at(0)<<endl;
        return 0;
    }
    bool AAA=true;
    for(int i=1;i<S.size();i++){
        if(S.at(i)!='9'){
            AAA=false;
        }
    }
    if(AAA){
    sum = S.at(0)-'0'+9*(S.size()-1);
    cout<< sum<<endl;
    }
    else{
     sum = S.at(0)-'0'-1+9*(S.size()-1);
    cout<< sum<<endl;       
    }
}