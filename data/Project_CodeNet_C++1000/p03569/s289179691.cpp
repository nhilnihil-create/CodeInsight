#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int nonxnum = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != 'x') nonxnum++;
    }

    bool isok = true;
    {
        int left = 0;
        int right = s.length()-1;
        while(left < right){
            while(s[left] == 'x') left++;
            while(s[right] == 'x') right--;
            if(left < right && s[left++] != s[right--]) isok = false;
        }
    }

    int ans = 0;
    if(isok){
        int left = 0;
        int right = s.length()-1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else if(s[left] == 'x'){
                left++;
                ans++;
            }else{
                right--;
                ans++;
            }
        }
    }else{
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}