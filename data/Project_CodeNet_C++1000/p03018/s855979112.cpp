#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    long ans = 0;
    long tmp = 0;
    for(int i=s.length()-1;i>=0;i--){
        if(i!=0 && s[i] == 'C'){
            i--;
            if(s[i]== 'B')tmp++;
            else if(s[i]=='C'){
                i++;
                tmp = 0;
            }else{
                tmp = 0;
            }
        }else if(s[i]=='A'){
            ans += tmp;
        }else{
            tmp = 0;
        }
    }
    cout << ans << endl;
}