#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin>>s;
    int start = 0, end = s.size()-1;
    int ans = 0;
    while(start<end){
        if(s[start] == s[end]){
            start++;
            end--;
        }
        else {
            if(s[start] == 'x'){
                ans++;
                start++;
            }
            else if(s[end] == 'x'){
                ans++;
                end--;
            }
            else {
                ans = -1;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
