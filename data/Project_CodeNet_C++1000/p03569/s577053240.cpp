#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int len = s.length();

    int left = 0;
    int right = len - 1;
    int ans = 0;
    int flag = 0;
    while(1){
        if(left >= right){
            break;
        }

        if(s[left] == s[right]){
            left++;
            right--;
        }else if(s[left] == 'x'){
            left++;
            ans++;
        }else if(s[right] == 'x'){
            right--;
            ans++;
        }else{
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        ans = -1;
    }

    cout << ans << endl;
}