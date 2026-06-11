#include <bits/stdc++.h> 
using namespace std;

int main(){

    string S;
    cin >> S;
    int size,count;
    size = S.size();
    count = 0;
    for(int i = 0;i<S.size();i++){
        if(S[i]=='x'){
            count ++;
        }
        if(count >=8){
            
            cout << "NO" <<endl;
            return 0;
        }
    }
    cout <<"YES"<<endl;
    
}