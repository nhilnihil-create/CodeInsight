#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int idx[3]={0,0,0};
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            idx[0]++;
        }else if(s[i]=='b'){
            idx[1]++;
        }else if(s[i]=='c'){
            idx[2]++;
        }
    }
    
    if(abs(idx[0]-idx[1])<=1&&abs(idx[1]-idx[2])<=1&&abs(idx[0]-idx[2])<=1){
        cout << "YES" << endl;
        //cout << idx[0] << " " << idx[1] << " " << idx[2] << endl;
    }else{
        cout << "NO" << endl;
        //cout << idx[0] << " " << idx[1] << " " << idx[2] << endl;
    }
    return 0;
}