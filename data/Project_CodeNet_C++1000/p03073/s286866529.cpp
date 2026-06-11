#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int sz;
    sz = s.size();
    int st;
    st = s[0]-'0';
    int cnt=0;
    for(int i=0; i<sz; i++){
        if(st==0){
            if(i%2==0){
                if(s[i]!='0') cnt++;
            }else{
                if(s[i]!='1') cnt++;
            }
        }else{
            //st=1
            if(i%2==0){
                if(s[i]!='1') cnt++;
            }else{
                if(s[i]!='0') cnt++;
            }
        }
    }
    cout << cnt << endl;
}


