#include <bits/stdc++.h>    
using namespace std;    
string s;    
unordered_map<int, int>cnt;    
int main(){    
    cin>>s;    
    int cur = 0, x;    
    cnt[cur] = 1;    
    for(int i = 0; i < s.size(); ++i){    
        cur ^= (1 << (s[i] - 'a'));    
        if(cur ==  0){    
            continue;    
        }    
        else{    
            x = 1e8;    
            if(cnt[cur] > 0){    
                x= min(x, cnt[cur]);    
            }    
            for(int j = 0; j < 26; ++j){    
                if((cur ^ (1 << j)) == 0){ x = 1; break;}    
                else{    
                    if(cnt[cur ^ (1 << j)] > 0) x = min(x, cnt[cur ^ (1 << j)] + 1);    
                    else{    
                        x = min(x, cnt[cur ^ (1 << (s[i] - 'a'))] + 1);    
                    }    
                }    
            }    
            cnt[cur] = x;    
        }    
    }    
    cout << cnt[cur] << endl;    
}    
     
/*  
题意：  
长度2e5的字符串，问最少需要分成多少个连续的子串，在子串内部的字符可以随意排列的情况下使得这些子串都是回文串。  
   
思路：对于子串，只要出现奇数次的字符不超过1个，该子串就是回文串。一共26个小写字母，可以用一个整数状压记录，第i  
位表示该字母出现多少次。某位为0表示出现偶数次，为1表示出现奇数次。这样就很容易维护答案了。  
*/  