#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin>>s;
    long ans = 0;
    long BCnum = 0;
    long i=s.size()-1;
    while(i>=0){
        if(i>0){
            if(s[i-1]=='B' & s[i]=='C'){
                BCnum++;
                i -= 2;
            }
            else if(s[i]=='A'){
                ans+=BCnum;
                i--;
            }
            else{
                BCnum = 0;
                i--;
            }
        }
        else{
            if(s[i]=='A'){
                ans+=BCnum;
            }
            i--;
        }
    }
    cout<<ans<<endl;
}
