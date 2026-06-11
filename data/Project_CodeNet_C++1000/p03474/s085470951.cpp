#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    int count =0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='-'){
            count++;
        }
    }
    bool before = false;
    bool after = false;
    if(count>1){
        cout<<"No"<<endl;
    }else{
        if(s[a]=='-' && s.size()-(a+1)==b){
            for(int i=0; i<a; i++){
                if(s[i]>='0' && s[i]<='9'){
                    before = true;
                }else{
                    before = false;
                    break;
                }
            }for(int i=a+1; i<s.size(); i++){
                if(s[i]>='0' && s[i]<='9'){
                    after = true;
                }else{
                    after = false;
                    break;
                }
            }
            if(before==true && after==true){
                cout<<"Yes"<<endl;
            }else{
                cout <<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }
}