#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int i;
    if(s.size()==2){
        cout << s <<endl;
    }
    else if(s.size()==3){
        for(i=0;i<3;i++){
            cout << s.at(2-i);
        }
        cout << endl;
    }
return 0;
}