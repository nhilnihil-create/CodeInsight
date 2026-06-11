#include<iostream>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int cnt[3] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a'){
            cnt[0]++;
        }else if(s[i] == 'b'){
            cnt[1]++;
        }else if(s[i] == 'c'){
            cnt[2]++;
        }
    }
    
    if(cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }
}