#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int left = 0, right;

    int count = 0;
    for(right = 1; right < n; right++){
        if(s[right-1] == '0' && s[right] == '1')count++;
        if(count == k) break;
    }
    
    
    for(; right < n ; right++){
        if(right < n-1){
            if(s[right] == '1' && s[right+1] == '0') break;
        }
    }
    //cout << right << endl;
    if(right == n) cout << n << endl;
    else{
        int max = right+1;
        while(right < n-1){
            left++;
            for(; !(s[left-1] == '0' && s[left] == '1'); left++);
            right++;
            for(; !(s[right-1] == '0' && s[right] == '1') && right < n; right++);
            if(right == n) right--;
            //cout << right;
            for(; right < n-1; right++){
                if(s[right] == '1' && s[right+1] == '0') break;
            }
            //if(right == n-1) right--;
            //if(right == n-1 && s[n-1] == '1') cout << right++;
            if(max < (right - left + 1)) max = right - left + 1;
            
            //cout << left << " " << right << endl;
        }
        cout << max << endl;
    }
}