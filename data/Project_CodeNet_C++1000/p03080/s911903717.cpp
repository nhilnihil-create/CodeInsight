#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;
 
int main(){
    
    char s[100];
    int N,Rc,Bc;
    Rc = 0;
    Bc = 0;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s[i];
    }

    for(int i=0;i<N;i++){
        if(s[i]=='R'){
            Rc+=1;
        }else{
            Bc+=1;
        }
    }

    if(Rc>Bc){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;

}