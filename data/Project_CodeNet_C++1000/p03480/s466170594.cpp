#include<iostream>
#include<array>
#include<string>

using namespace std;

int main(){
    string s;
    int length,number=0,ans;
    cin>>s;
    length = static_cast<int>(s.size());
    if(length%2 == 0){
        int i = length/2 - 1;
        int j = length/2;
        while(s[i] == s[j] && s[i] == s[i+1]){
            i--;
            j++;
            number++;
        }
        ans = (length+2*number)/2;
    }else{
        int i = (length-1)/2-1;
        int j = (length-1)/2+1;
        while(s[i] == s[j] && s[i] == s[i+1] && i >= 0){
            i--;
            j++;
            number++;
        }
        ans = (length + 2*number + 1)/2;
    }
//  cout<<number<<endl;
    cout<<ans<<endl;

}