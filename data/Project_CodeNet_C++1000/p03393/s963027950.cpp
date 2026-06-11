#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    if(n<26){
        for(char c='a';c<='z';c++){
            if(find(s.begin(),s.end(),c)==s.end()){
                cout<<s+c<<endl;
                return 0;
            }
        }
    }else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout<<-1<<endl;
            return 0;
        }
        for(int i=0;i<25;i++){
            if(s[25-i]>s[24-i]){
                for(int j=0;j<24-i;j++) cout<<s[j];
                for(int j=25;j>=25-i;j--){
                    if(s[j]>s[24-i]){
                        cout<<s[j];
                        break;
                    }
                }
                break;
            }
        }
        cout<<endl;
    }
}