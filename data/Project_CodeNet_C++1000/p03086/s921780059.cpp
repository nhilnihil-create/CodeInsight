#include <bits/stdc++.h>
using namespace std;

bool check(char a){
    if(a == 'A'||a == 'C'||a == 'T'||a == 'G'){
        return true;
    }else{
        return false;
    }
}

int main(){
    string S;
    cin >> S;
    int ans = 0;
    for(int i=0;i<S.size();i++){
        if(check(S.at(i))){
            if(i==S.size()-1) ans = max(ans,1);
            for(int j=i+1;j<S.size();j++){
                if(!check(S.at(j))) break;
                ans = max(ans, j-i+1);
            }
        }
    }
    cout << ans <<endl;
    return 0;
}