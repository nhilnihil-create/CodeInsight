#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin>>S;
    int x=0;

        for(int i=0 ; i<S.size() ; i++){
        if(S[i]=='+'){
           x++;
           }
           else{
            x--;
           }
    }
    cout << x << endl;
return 0;
}
